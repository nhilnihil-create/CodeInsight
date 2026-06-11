#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define lol(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
typedef long long ll;
using namespace std;

int main(){
    ll n;
    cin>>n;
    ll sum=0,mini=mod;
    bool ok=true;
    lol(i,n){
	ll a,b;cin>>a>>b;
	if(a!=b)ok=false;
	sum+=b;
	if(a>b)mini=min(mini,b);
    }
    if(ok)return cout<<0<<endl,0;
    return cout<<sum-mini<<endl,0;
}
