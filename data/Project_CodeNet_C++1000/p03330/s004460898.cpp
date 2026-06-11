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
    int N, C;
    cin >> N >> C;
    vector<vector<int>> D(C, vector<int>(C));
    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < C; i++) for (int j = 0; j < C; j++) scanf("%d", &D[i][j]);
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        scanf("%d", &A[i][j]); A[i][j]--;
    }

    vector<vector<int>> v(3, vector<int>(C));
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) v[(i+j)%3][A[i][j]]++;
    int minD = INF;
    for (int c1 = 0; c1 < C; c1++) {
        for (int c2 = 0; c2 < C; c2++) {
            if (c1 == c2) continue;
            for (int c3 = 0; c3 < C; c3++) {
                if (c2 == c3 || c1 == c3) continue;
                int cur = 0;
                for (int j = 0; j < C; j++) {
                    cur += D[j][c1] * v[0][j];
                    cur += D[j][c2] * v[1][j];
                    cur += D[j][c3] * v[2][j];
                }
                minD = min(minD, cur);
            }
        }
    }

    cout << minD << '\n';
}
