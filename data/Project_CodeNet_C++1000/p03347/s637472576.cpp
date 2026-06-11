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
ll a[200010];
int main(){
    cin>>N;
	for(ll i=0;i<N;i++){
		cin>>a[i];
	}
	ll ans=0;
	if(a[0]!=0){
		cout<<-1;
		return 0;
	}
	for(ll i=0;i<N-1;i++){
		if(a[i]+1<a[i+1]){
			cout<<-1;
			return 0;
		}
		if(a[i]+1==a[i+1]){
			ans++;
		}else{
			ans+=a[i+1];
		}
	}
	cout<<ans;
    return 0;
}