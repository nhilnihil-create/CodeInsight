#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define debug(n,v) cout<<#v<<":";for(int i=0;i<n;i++)cout<<v[i]<<" ";cout<<endl; 
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main(){
    int n;
    cin>>n;
    string a,b,c;
    cin>>a>>b>>c;
    int ans=0;
    rep(i,n){
        if(a[i]==b[i]&&b[i]==c[i]) continue;
        if(a[i]==b[i]||a[i]==c[i]||b[i]==c[i]) ans++;
        else ans+=2;
    }
    cout<<ans<<endl;
    return 0;
}