#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;
typedef long long LL;
static long long INF = (1LL<<62);

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, M; cin >> N >> M;
	vector<pair<int, int>> V;
	for(int i=0; i<M; i++){
		int a, b; cin >> a >> b;
		a--; b--;
		V.push_back(make_pair(a, b));
	}

	sort(V.begin(), V.end());
	vector<pair<int,int>> A;
	int bl = -1, br = -1;
	for(int i=0; i<V.size(); i++){
		auto p = V[i];
		int l = p.first;
		int r = p.second;
		if(i == 0){
			A.push_back(make_pair(l, r));
			bl = l; br = r;
		}
		else if(br <= l){
			A.push_back(make_pair(l, r));
			bl = l;
			br = r;
		}
		else{
			bl = l;
			br = min(br, r);
		}
	}
	int ans = (int)A.size();
	printf("%d\n", ans);
	return 0;
}
