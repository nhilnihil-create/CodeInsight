#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(int i=0;i<n;i++)
using Graph = vector<vector<int>>;
using pint = pair<int,int>;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

int main(){
    int n;cin>>n;
    ll a[n],b[n],c[n];
    ll ans=0;
    rep(i,n){
        cin>>a[i]>>b[i];
        c[i]=a[i]+b[i];
        ans-=b[i];
    }
    sort(c,c+n,greater<ll>());
    //int k=n/2;
    //if(n%2==1) k++;
    rep(i,n){
        if(i%2==0) ans+=c[i];
    }
    cout<<ans<<"\n";
}
