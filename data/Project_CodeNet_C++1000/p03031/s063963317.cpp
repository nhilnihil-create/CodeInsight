#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define per1(i,n) for(int i=n;i>0;i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,ans=0;
    cin>>n>>m;
    int k[m],s[m][n],p[m];
    rep(i,m){
        cin>>k[i];
        rep(j,k[i]) cin>>s[i][j];
    }
    rep(i,m) cin>>p[i];
    rep(i,pow(2,n)){
        int b=0;
        rep(j,m){
            int a=0;
            rep(l,k[j]) if(i&(1<<(s[j][l]-1))) a++;
            if(a%2==p[j]) b++;
        }
        if(b==m) ans++;
    }
    cout<<ans;
}