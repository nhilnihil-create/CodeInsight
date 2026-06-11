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
    int n,q;
    string s;
    cin>>n>>s>>q;
    while(q--) {
        int k;
        cin>>k;
        vector<ll> c(n+1),m1(n+1),m2(n+1);
        for(int i = 0; i < n; i++) {
            c[i+1]=c[i];
            m1[i+1]=m1[i];
            m2[i+1]=m2[i];

            if(s[i]=='C') {
                c[i+1]++;
                m2[i+1]+=m1[i+1];
            }
            if(s[i]=='M') m1[i+1]++;
        }
        //for(int x:c) cout<<x<<" ";cout<<endl;
        //for(int x:m1) cout<<x<<" ";cout<<endl;
        //for(int x:m2) cout<<x<<" ";cout<<endl;

        ll ans=0;
        for(int i = 0; i < n; i++) {
            if(s[i]=='D') {
                ans+=m2[min(n,i+k)]-m2[i];
                //cout<<m2[min(n,i+k)]-m2[i]<<endl;
                ans-=m1[i+1]*(c[min(n,i+k)]-c[i]);
                //cout<<m1[i+1]<<" "<<c[min(n,i+k)]<<" "<<c[i]<<endl;
                //cout<<ans<<endl;
            }
        }
        cout<<ans<<endl;
        //break;
    }
}