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
    for (int i = 0; i < C; i++) for (int j = 0; j < C; j++) cin >> D[i][j];
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> A[i][j];
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) A[i][j]--;

    vector<map<int, int>> mp(3);
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) mp[(i+j)%3][A[i][j]]++;
    int minD = INF;
    for (int c1 = 0; c1 < C - 2; c1++) {
        for (int c2 = c1+1; c2 < C - 1; c2++) {
            for (int c3 = c2+1; c3 < C; c3++) {
                vector<int> p{c1, c2, c3};
                do {
                    int cur = 0;
                    for (int i = 0; i < 3; i++)
                        for (auto m : mp[i])
                            cur += D[m.first][p[i]] * m.second;
                    minD = min(minD, cur);
                } while(next_permutation(p.begin(), p.end()));
            }
        }
    }

    cout << minD << '\n';
}
