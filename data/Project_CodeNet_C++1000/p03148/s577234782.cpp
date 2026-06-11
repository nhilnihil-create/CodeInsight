#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
ll N,K,t,d;
pair<ll,int> A[100010];
int main(){
	cin >> N >> K;
	for(int i=1;i<=N;i++){
		cin >> t >> d;
		A[i] = {d,t};
	}
	map<int,ll> m;
	sort(A+1,A+N+1);
	ll ans = 0,sum = 0,r = 0;
	for(int i=N;i>=1;i--){
		if(i>=N-K+1){
			m[A[i].second]++;
			sum += A[i].first;
			if(i==N-K+1){
				ll s = m.size();
				ans = sum + s*s;
				r = N-K+1;
			}
		}else{
			if(!m.count(A[i].second)){
				m[A[i].second]++;
				while(r<=N && m[A[r].second]==1) r++;
				if(r==N+1) break;
				sum += A[i].first-A[r].first;
				m[A[r].second]--; r++;
				ll s = m.size();
				ans = max(ans,sum+s*s);
			}
		}
	}
	cout << ans << endl;
}
