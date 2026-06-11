#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

typedef long long ll;

int main() {
    int n = 10;
    int h,w; cin>>h>>w;
    
//    ll INF =100000007;
    ll a[n][n];
    rep(i,n){
        rep(j,n){
            cin>>a[i][j];
        }
    }
    
    rep(k,n){
        rep(i,n){
            rep(j,n){
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
                }
            }
        }
    
    ll ans = 0;
    ll tmp;
    rep(i,h){
        rep(j,w){
            cin>>tmp;
            if(tmp!=-1) ans+= a[tmp][1];
        }
    }
    
    cout<<ans<<endl;
 	return 0;
}