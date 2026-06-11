#include <bits/stdc++.h>
#define s second
#define f first
#define pb push_back
#define endl '\n'
using namespace std;


typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const int MAX = 1e6 + 10;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<bool> DP(MAX,0);

	int N, K;
	cin >> N >> K;

	vector<int> V(N);

	for(auto &x : V) cin >> x;

	for(int i = 0; i <= K; i++){
		if(DP[i]) continue;
		for(auto j : V) DP[i + j] = 1;
	}

	cout << (DP[K] ? "First" : "Second") << endl;

	return 0;
}
