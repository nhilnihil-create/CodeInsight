#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define sz(x) int(x.size())
#define get_unique(x) x.erase(std::unique(all(x)), x.end());
typedef long long ll;
const int INF = 1e9;
const ll MOD = 1e9+7;
const ll LINF = 1e18;
const double PI=acos(-1);
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

int main() {
    int n;
    cin>>n;
    vector<int> d(n),cnt(13,0);
    cnt[0]++;
    for(int i = 0; i < n; i++) {
        cin>>d[i];
        cnt[d[i]]++;
        if(cnt[d[i]]>2) {
            cout<<0<<endl;
            return 0;
        }
    }
    if(cnt[0]>1 || cnt[12]>1) {
        cout<<0<<endl;
        return 0;
    }

    vector<int> one,two;
    for(int i = 0; i < 13; i++) {
        if(cnt[i]==1) {
            one.push_back(i);
        }
        if(cnt[i]==2) {
            two.push_back(i);
            two.push_back((24-i)%24);
        }
    }

    int ans=0;
    int k=sz(one);
    for(int bit = 0; bit < (1<<k); bit++) {
        vector<int> time;
        for(int x:two) time.push_back(x);
        for(int i = 0; i < k; i++) {
            if(bit&(1<<i)) time.push_back(one[i]);
            else time.push_back((24-one[i])%24);
        }
        sort(all(time));
        time.push_back(24);

        int now=24;
        for(int i = 0; i < sz(time)-1; i++) {
            chmin(now,abs(time[i]-time[i+1]));
        }
        chmax(ans,now);
    }

    cout<<ans<<endl;

}

