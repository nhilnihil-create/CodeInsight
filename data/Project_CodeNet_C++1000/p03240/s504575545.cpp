#include<bits/stdc++.h>
#define INFTY 10000000000
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
const int MOD=1000000007;
const int di[4] = {-1,0,1,0};
const int dj[4] = {0,-1,0,1};
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
int main(){
    int n;cin>>n;
    vector<int> x(n),y(n);
    vector<ll> h(n);
    vector<ll> hi(n,0);
    ll eh;
    rep(i,n)cin>>x[i]>>y[i]>>h[i];
    rep(c_x,101)rep(c_y,101){
        int ok = 1;
        rep(i,n){
            if(h[i]==0)continue;
            if(h[i]>0){hi[i]=abs(x[i]-c_x)+abs(y[i]-c_y)+h[i];eh = hi[i];}
        }
        rep(i,n){
            if(hi[i]>0&&hi[i]!=eh){
                ok = 0;break;
            }
            if(hi[i] ==0 && eh-abs(x[i]-c_x)-abs(y[i]-c_y)>0){
                ok = 0;break;
            }
        }
    if(ok&&eh>=1){
        cout<<c_x<<" "<<c_y<<" "<<eh<<endl;
        return 0;
    }
    }
    return 0;
}