#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(false);
	ll N,out=0;
	cin>>N;
	vector<ll> A(N),B(N);
	for(int i=0;i<N;i++) cin>>A[i];
	for(int i=0;i<N;i++) cin>>B[i];
	for(ll i=29;i>=0;i--){
		ll high=1<<(i+1),low=1<<i;
		for(int j=0;j<N;j++){
			B[j]%= high;
			A[j]%= high;
		}
		sort(B.begin(),B.end());
		ll ans=0;
		for(int j=0;j<N;j++){
			ll reg=0;
			if(low -A[j] >= 0){
				reg += lower_bound(B.begin(), B.end(), high - A[j] ) - lower_bound(B.begin(), B.end(), low - A[j] );
			}else{
				reg += lower_bound(B.begin(), B.end(), high - A[j] ) - B.begin();
				reg += lower_bound(B.begin(), B.end(), high ) - lower_bound(B.begin(), B.end(), high + low - A[j] );
			}
			ans+=reg;
		}
		//cout<<reg<<" ";
		if(ans&1) out += low;
	}
	cout<<out<<endl;
	return 0;
}
