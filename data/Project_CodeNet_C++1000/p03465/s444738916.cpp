#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>
#include<iomanip>
#include<bitset>
#define mod 1000000007
using namespace std;
typedef long long ll;
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)
#define mad(a,b) a=(a+b)%mod
#define mul(a,b) a=a*b%mod

#define N 310
ll n;
bitset<4000010> bi;
int main(){
    bi[0]=1;
    cin>>n;
    for(int i=0;i<n;i++){
	ll a; cin>>a;
	bi|=(bi<<a);
    }
    vector<ll> v;
    for(int i=1;i<4000010;i++){
	if(bi[i])v.push_back(i);
    }
    cout<<v[(v.size()-1)/2]<<endl;
}


