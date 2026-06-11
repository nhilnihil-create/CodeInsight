#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2,tune=native")

#include <x86intrin.h>
#include <bits/stdc++.h>

using namespace std;

vector<int> l;

int N, A, B, C;

const int INF = 1000000007;

int dfs (int index, int a, int b, int c) {
    if (index == N)
	return (a && b && c) ? abs(a - A) + abs(b - B) + abs(c - C) - 30 : INF;
	// Remove the extra 10MP from each of A, B, C.
    int branch0 = dfs(index + 1, a, b, c);
    int branchA = dfs(index + 1, a + l[index], b, c) + 10;
    /* +10MP for every bamboo piece. 
     * Note that this causes an extra 10 points (merges = pieces - 1). */
    int branchB = dfs(index + 1, a, b + l[index], c) + 10;
    int branchC = dfs(index + 1, a, b, c + l[index]) + 10;
    return min({branch0, branchA, branchB, branchC});
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> A >> B >> C;
    l.resize(N);
    for (int i = 0; i < N; i++) cin >> l[i];
    cout << dfs(0, 0, 0, 0);
    return 0;
}