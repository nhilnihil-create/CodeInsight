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
    int N, C, c;
    cin >> N >> C;
    vector<vector<int> > cost(C, vector<int>(C)), color(N, vector<int>(N));
    for (int i = 0; i < C; i++) for (int j = 0; j < C; j++) cin >> cost[i][j];
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        cin >> c; color[i][j] = c - 1;
    }
    vector<map<int, int> > mp(3);
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
        mp[(i + j) % 3][color[i][j]]++;

    int minC = INF;
    for (int c1 = 0; c1 < C - 2; c1++) {
        for (int c2 = c1 + 1; c2 < C - 1; c2++) {
            for (int c3 = c2 + 1; c3 < C; c3++) {
                vector<int> p{c1, c2, c3};
                do {
                    int tmp = 0;
                    for (int i = 0; i < 3; i++) {
                        int ncolor = p[i];
                        for( auto it = mp[i].begin(); it != mp[i].end() ; ++it )
                            tmp += cost[it->first][ncolor] * it->second;
                    }
                    minC = min(tmp, minC);
                } while(next_permutation(p.begin(), p.end()));
            }
        }
    }
    cout << minC << '\n';
}
