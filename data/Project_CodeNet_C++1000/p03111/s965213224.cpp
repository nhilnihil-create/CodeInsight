#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e9;

long long N, A, B, C;
long long l[8];

long long dfs(long long cur, long long a, long long b, long long c){
	if (cur == N){
		return (min({a,b,c}) > 0)? abs(a - A) + abs(b - B) + abs(c - C) - 30 : INF;
	}

	long long ret0 = dfs(cur + 1, a, b, c);
	long long ret1 = dfs(cur + 1, a + l[cur], b, c) + 10;
	long long ret2 = dfs(cur + 1, a, b + l[cur], c) + 10;
	long long ret3 = dfs(cur + 1, a, b, c + l[cur]) + 10;

	return min({ret0, ret1, ret2 , ret3});
}

int main(){
	cin >> N >> A >> B >> C;
	for (long long i = 0; i < N; i++){
		cin >> l[i];
	}

	cout << dfs(0, 0, 0, 0) << endl;
	return 0;
}
