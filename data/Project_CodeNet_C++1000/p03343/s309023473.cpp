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
ll binarySearch(function<bool(ll)> check, ll ok, ll ng) {
  while ((ok - ng > 1) || (ng - ok > 1)) {
    ll mid = (ok + ng) / 2;
    if (check(mid)) ok = mid;
    else ng = mid;
  }
  return ok;
}
ll N,K,Q;
ll A[2010];
bool Check(ll diff){
	for(ll i=0;i<N;i++){
		ll deleteCnt=0;
		ll nowSize=0;
		ll inRangeCnt=0;
		for(ll j=0;j<N;j++){
			if(A[i]<=A[j]){
				nowSize++;
				if(A[j]<=A[i]+diff)inRangeCnt++;
			}else{
				deleteCnt+=max(0ll,min((nowSize+1-K),inRangeCnt));
				nowSize=0;
				inRangeCnt=0;
			}
		}
		deleteCnt+=max(0ll,min((nowSize+1-K),inRangeCnt));
		if(deleteCnt>=Q)return false;
	}
	return true;
}
int main(){
    cin>>N>>K>>Q;
	for(ll i=0;i<N;i++){
		cin>>A[i];
	}
	cout<<binarySearch(Check,-1,INF)+1<<endl;
    return 0;
}