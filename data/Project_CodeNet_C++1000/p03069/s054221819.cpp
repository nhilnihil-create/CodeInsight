#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1LL<<60;
const double EPS = 1e-10;
const ll mod=1000000007;

ll W[200010]={},B[200010]={};

int main(void){
    ll n;
    string s;
    cin>>n>>s;
    for(int i=0;i<n;i++){
        if(i>0) W[i]=W[i-1];
        if(s[i]=='.') W[i]++;
    }
    for(int i=n-1;i>=0;i--){
        if(i!=n-1) B[i]=B[i+1];
        if(s[i]=='#') B[i]++;
    }
    ll ans=min(n-W[n-1],n-B[0]);
    for(int i=0;i<n-1;i++){
        ans=min(ans,n-W[i]-B[i+1]);
    }
    cout<<ans<<endl;
}