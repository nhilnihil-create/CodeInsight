#include<iostream>
#include<iomanip>
#include<cassert>
#include<math.h>
#include<complex>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<unordered_map>
#include<functional>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=2e18;
const ll MOD=1e9+7;

ll N;
ll ans[20010];
int main(){
    cin>>N;
	if(N==3){
		cout<<"2 5 63";
		return 0;
	}
	if(N<=15000){
		ll r;
		if(N%2==0){
			if(N<=6){
				r=2;
			}
			else{
				r=(N-1)/6*6;
			}
		}else{
			r=(N-4)/6*6+3;
		}
		for(ll i=1;i<=r;i++){
			ans[i]=i*2;
		}
		for(ll i=r+1;i<=N;i++){
			ans[i]=(i-r)*6-3;
		}
	}	
	if(N>15000){
		for(ll i=1;i<=15000;i++){
			ans[i]=i*2;
		}
		for(ll i=15000+1;i<=N;i++){
			ans[i]=6*(i-15000)-3;
		}
		if(N%2==1){
			ans[3]=6*(N+1-15000)-3;
		}
	}
	for(ll i=1;i<=N;i++){
		cout<<ans[i]<<" ";
	}	
    return 0;
}