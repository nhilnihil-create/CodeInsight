#include <iostream>
#include <vector>
#include <utility>
using namespace std;
struct unionfind{
	vector<int> p, sz;
	unionfind(int n){
		p = vector<int>(n, -1);
		sz = vector<int>(n, 1);
	}
	int root(int x){
		if (p[x] == -1){
			return x;
		} else {
			p[x] = root(p[x]);
			return p[x];
		}
	}
	bool same (int x, int y){
		return root(x) == root(y);
	}
	pair<int, int> unite(int x, int y){
		x = root(x);
		y = root(y);
		pair<int, int> ans = make_pair(sz[x], sz[y]);
		p[y] = x;
		sz[x] += sz[y];
		return ans;
	}
};
int main(){
	int N, M;
	cin >> N >> M;
	vector<int> A(M), B(M);
	for (int i = 0; i < M; i++){
		cin >> A[i] >> B[i];
		A[i]--;
		B[i]--;
	}
	vector<long long> ans(M);
	ans[M - 1] = (long long) N * (N - 1) / 2;
	unionfind G(N);
	for (int i = M - 2; i >= 0; i--){
		if (!G.same(A[i + 1], B[i + 1])){
			pair<int, int> sz = G.unite(A[i + 1], B[i + 1]);
			ans[i] = ans[i + 1] - (long long) sz.first * sz.second;
		} else {
			ans[i] = ans[i + 1];
		}
	}
	for (int i = 0; i < M; i++){
		cout << ans[i] << endl;
	}
}