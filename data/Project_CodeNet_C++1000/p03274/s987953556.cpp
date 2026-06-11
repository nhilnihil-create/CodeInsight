#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<utility>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ll> p;
typedef unsigned long long int ull;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const ll INF=2e18;
ll MOD=1e9+7;

ll power(ll a,ll x){
    ll res=1;
    while(x>0){
        if(x&1) res=res*a%13;
        a=a*a%13;
        x>>=1;
    }
    return res;
}

int main(){
    int n,k;cin>>n>>k;
    vector<ll> x(n);
    for(int i=0;i<n;i++) cin>>x[i];
    ll ans=INF;
    for(int i=0;i+k-1<n;i++){
        ans=min(ans,x[i+k-1]-x[i]+min(abs(x[i]),abs(x[i+k-1])));
    }
    cout<<ans<<endl;
    return 0;
}