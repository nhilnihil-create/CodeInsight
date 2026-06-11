#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;
typedef long long ll;
int N;

int main(){
	cin >> N;
	vector<ll> A(N+1,-1),B(N+1,-1),v;
	for(int i=1;i<=N;i++){
		cin >> A[i];
	}
	for(int i=1;i<=N;i++){
		cin >> B[i];
	}
	ll ans = 0;
	for(int k=0;k<=29;k++){
		ll mod = (1<<(k+1));
		v.push_back(-1);
		for(int i=1;i<=N;i++) v.push_back(B[i]%mod);
		sort(v.begin(),v.end());
		ll cnt = 0,t = (1<<k);
		for(int i=1;i<=N;i++){
			int id1 = lower_bound(v.begin(),v.end(),t-A[i]%mod)-v.begin();
			int id2 = lower_bound(v.begin(),v.end(),2*t-A[i]%mod)-v.begin();
			int id3 = lower_bound(v.begin(),v.end(),3*t-A[i]%mod)-v.begin();
			int id4 = lower_bound(v.begin(),v.end(),4*t-A[i]%mod)-v.begin();
			cnt += (id2-id1) + (id4-id3);
			if(id1==0 && id2!=0) cnt--;
			if(id3==0 && id4!=0) cnt--;
		}
		if(cnt>=0 && cnt%2==1) ans += (1<<k);
		v.clear();
	}
	cout << ans << endl;
}