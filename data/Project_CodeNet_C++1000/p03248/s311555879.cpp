#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n-1);i>=0;i--)
#define FOR(i,n,m) for(int i=n;i<=(int)(m);i++)
#define RFOR(i,n,m) for(int i=(int)(n);i>=m;i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) int(x.size())
#define get_unique(x) x.erase(std::unique(all(x)), x.end());
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
const double PI=acos(-1);
using namespace std;
vector<int> dx={1,0,-1,0};
vector<int> dy={0,1,0,-1};
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

int main() {
    string s;
    cin>>s;
    int n=sz(s);
    rep(i,(n-1)/2) {
        if(n-2-i<i) break;
        if(s[i]!=s[n-2-i]) {
            cout<<-1<<endl;
            return 0;
        }
    }
    if(s[n-1]=='1' || s[0]=='0' || s[n-2]=='0') {
        cout<<-1<<endl;
        return 0;
    }
    
    int now=1;
    rep(i,n) {
        if(i==0) continue;
        cout<<now<<" "<<i+1<<endl;
        if(i<=n/2 && s[i-1]=='1') now=i+1;
    }
}
