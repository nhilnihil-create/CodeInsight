#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<set>
#include<stack>
#include<queue>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define rep(i,n) for(ll i=0;i<n;i++)
#define repr(i,n) for(ll i=n;i>=0;i--)
#define INF 1e9+7
#define LLINF 1e18
using namespace std;
const int MOD = 1e9 +7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    char field[310][310];
    cin>>n;
    rep(i,n){
        rep(j,n){
            cin>>field[i][j];
        }
    }
    ll ans=0;
    rep(k,n){
        bool flag=true;
        rep(i,n){
            for(int j=i+1;j<n;j++){
                ll xk =(j-k<0)? j+n-k :j-k;
                ll yk =(i-k<0)? i+n-k :i-k;
                if(field[i][xk] !=field[j][yk]) flag=false;
            }
        }
        if(flag) ans++;
    } 
    cout<<ans*n<<endl;
    return 0;
}