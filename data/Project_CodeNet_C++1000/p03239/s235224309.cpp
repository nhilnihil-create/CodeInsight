#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n,T;cin>>n>>T;
    int res=10000;
    rep(i,n){
        int c,t;cin>>c>>t;
        if(t>T)continue;
        chmin(res,c);
    }
    if(res==10000)cout<<"TLE"<<endl;
    else cout<<res<<endl;
}