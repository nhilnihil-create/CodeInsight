#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;

vector<P> prime_factorize(ll N){
	vector<P> ans;
	for(ll a = 2; a*a <= N; a++){
		if(N%a == 0){
			ll ex = 0;
			while(N%a == 0){
				ex++;
				N /= a;
			}
			ans.push_back(P(a, ex));
		}
	}
	if(N != 1) ans.push_back(P(N, 1));
	return ans;
}

signed main(){
  int n; cin >> n;
  vector<int> data(98, 0);
  for(int i = 2; i <= n; i++){
    vector<P> vec = prime_factorize(i);
    for(int j = 0; j < vec.size(); j++) data[vec[j].first] += vec[j].second;
  }  
  int c74 = 0, c14 = 0, c24 = 0, c4 = 0, c2 = 0;
  for(int i = 0; i < 98; i++){
    if(data[i] >= 74) c74++;
    if(data[i] >= 14) c14++;
    if(data[i] >= 24) c24++;
    if(data[i] >= 4) c4++;
    if(data[i] >= 2) c2++;
  }
  int ans = c4 * (c4 - 1) * (c2 - 2) / 2 + c24 * (c2 - 1) + c74 + (c4 - 1) * c14;
  cout << ans << endl;
}