#include <iostream>

using namespace std;

const int UNIONFIND_MAX = 1e5 + 1;

long long par[UNIONFIND_MAX];
long long num[UNIONFIND_MAX];

void unionfind_init(int n){
	for (int i = 0; i < n; i++){
		par[i] = i;
		num[i] = 1;
	}
}

// return the root
int unionfind_root(int x){
	if(par[x] == x){
		// x is root
		return x;
	} else {
		// compress the path
		return par[x] = unionfind_root(par[x]);
	}
}

// check two set is the same
bool unionfind_same(int x, int y){
	return unionfind_root(x) == unionfind_root(y);
}

// unite two set
void unionfind_unite(int x, int y){
	x = unionfind_root(x);
	y = unionfind_root(y);
	if(x == y){
		return;
	}
	par[x] = y;
	num[y] += num[x];
	num[x] = num[y];
}

long long unionfind_size(int x){
	return num[unionfind_root(x)];
}

int main(){
	long long N, M;
	cin >> N >> M;
	long long A[M], B[M];
	for (long long i = 0; i < M; i++){
		cin >> A[i] >> B[i];
	}

	unionfind_init(N + 1);

	long long ans[M+1] = {0};
	ans[M] = N * (N - 1) / 2;

	for (long long i = M - 1; i >= 0; i--){
		if (unionfind_same(A[i], B[i])){
			ans[i] = ans[i + 1];
		} else {
			ans[i] = ans[i + 1] - unionfind_size(A[i]) * unionfind_size(B[i]);
			unionfind_unite(A[i], B[i]);
		}
	}

	for (long long i = 1; i <= M; i++){
		cout << ans[i] << endl;
	}
	return 0;
}
