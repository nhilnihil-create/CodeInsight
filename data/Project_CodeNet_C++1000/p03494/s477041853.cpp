#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n;cin>>n;
    vector<ll> a(n);
    ll res=1e10;
    rep(i,n){
        ll a;cin>>a;
        ll cou=0;
        while(a%2==0){
            cou++;
            a/=2;
        }
        chmin(res,cou);
    }
    cout<<res<<endl;
}
