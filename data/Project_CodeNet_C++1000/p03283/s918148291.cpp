/*
    Problem 79
    https://atcoder.jp/contests/abc106/tasks/abc106_d
*/
#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<int>> train(N+1, vector<int>(N+1));
    for (int i = 0; i < M; i++) {
        int l, r;
        cin >> l >> r;
        train[l][r]++;
    }
    vector<vector<int>> prefixSum(N+2, vector<int>(N+2));
    for (int i = 0; i < N+1; i++) for (int j = 0; j < N+1; j++)
        prefixSum[i+1][j+1] =
            prefixSum[i+1][j] + prefixSum[i][j+1] - prefixSum[i][j] + train[i][j];

    for (int i = 0; i < Q; i++) {
        int p, q;
        cin >> p >> q;
        q++;
        cout << prefixSum[q][q] + prefixSum[p][p] - prefixSum[p][q] - prefixSum[q][p] << '\n';
    }
}