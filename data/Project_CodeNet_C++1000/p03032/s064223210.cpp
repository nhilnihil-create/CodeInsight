#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
using Graph = vector<vector<int>>;
static long long INF = (1LL<<62);

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	LL N, K; cin >> N >> K;
	vector<LL> V;
	for(int i=0; i<N; i++){
		LL v; cin >> v;
		V.push_back(v);
	}

	LL ans = INF*(-1);
	for(int i=0; i<=K; i++){
		for(int j=0; j<=K; j++){
			if(i+j > K || i+j > N) break;
			deque<LL> W;
			for(int s=0; s<i; s++){
				W.push_back(V[s]);
			}
			for(int s=0; s<j; s++){
				W.push_back(V[V.size()-1-s]);
			}
			if(W.size() > 0){
				sort(W.begin(), W.end());
			}
			for(int s=0; s<K-(i+j); s++){
				if(W.size() < 1) break;
				LL b = W.front();
				if(b < 0){
					W.pop_front();
				}
			}
			LL sum = 0;
			for(int s=0; s<W.size(); s++){
				if(W.size() < 1) break;
				sum += W[s];
			}
			if(ans < sum){
				ans = sum;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
