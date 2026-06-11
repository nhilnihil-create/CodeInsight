#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>
#include<iomanip>
#include<bitset>
#define mod 998244353
using namespace std;
typedef long long ll;
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)
#define mad(a,b) a=(a+b)%mod
#define mul(a,b) a=a*b%mod

#define N 600010
ll n,l[N],r[N];
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
	cin>>l[i]>>r[i];
    }
    sort(l,l+n,greater<ll>());
    sort(r,r+n);
    ll lsum=0,rsum=0;
    ll ans=0;
    for(int i=0;i<n;i++){
	chmax(ans,lsum-rsum);
	chmax(ans,lsum-rsum+l[i]*2);
	chmax(ans,lsum-rsum-r[i]*2);
	lsum+=2*l[i];
	rsum+=2*r[i];
    }
    cout<<ans<<endl;
}


