#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include <limits.h>

using namespace std;

typedef long long ll;

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

vector<vector<vector<vector<int>>>> dp1;
vector<vector<vector<vector<int>>>> dp2;

int main(void) {
    string S;
    cin >> S;
    int slen = (int) S.size();

    dp1.resize(slen + 1);
    dp2.resize(slen + 1);
    for (int i = 0; i < slen + 1; i++) {
        dp1[i].resize(10);
        dp2[i].resize(10);
        for (int j = 0; j < 10; j++) {
            dp1[i][j].resize(10);
            dp2[i][j].resize(10);
            for (int k = 0; k < 10; k++) {
                dp1[i][j][k].resize(10, 0);
                dp2[i][j][k].resize(10, 0);
            }
        }
    }

    dp1[0][0][0][0] = 1;
    for (int i = 0; i < slen; i++) {
        if (i != 0) {
            dp2[i][0][0][0] = 1;
        }
        for (int j = 0; j < 9; j++) {
            for (int k = 0; k < 9; k++) {
                for (int l = 0; l < 9; l++) {
#ifdef DEBUG
                    printf("i: %d, j: %d, k: %d, l: %d\n", i, j, k, l);
#endif
                    const int d = S[i] - '0';

                    // dp1 -> dp1
                    if (d == 3) {
#ifdef DEBUG
                        printf("[1]: += %d\n", dp1[i][j][k][l]);
#endif
                        dp1[i + 1][j + 1][k][l] += dp1[i][j][k][l];
                    } else if (d == 5) {
#ifdef DEBUG
                        printf("[2]: += %d\n", dp1[i][j][k][l]);
#endif
                        dp1[i + 1][j][k + 1][l] += dp1[i][j][k][l];
                    } else if (d == 7) {
#ifdef DEBUG
                        printf("[3]: += %d\n", dp1[i][j][k][l]);
#endif
                        dp1[i + 1][j][k][l + 1] += dp1[i][j][k][l];
                    } else {
                        // printf("[4]: += %d\n", dp1[i][j][k][l]);
                        // dp1[i + 1][j][k][l] += dp1[i][j][k][l];
                    }

                    // dp1 -> dp2
                    for (int x = 0; x < d; x++) {
                        if (x == 3) {
#ifdef DEBUG
                            printf("[5]: += %d\n", dp1[i][j][k][l]);
#endif
                            dp2[i + 1][j + 1][k][l] += dp1[i][j][k][l];
                        } else if (x == 5) {
#ifdef DEBUG
                            printf("[6]: += %d\n", dp1[i][j][k][l]);
#endif
                            dp2[i + 1][j][k + 1][l] += dp1[i][j][k][l];
                        } else if (x == 7) {
#ifdef DEBUG
                            printf("[7]: += %d\n", dp1[i][j][k][l]);
#endif
                            dp2[i + 1][j][k][l + 1] += dp1[i][j][k][l];
                        } else {
                            // printf("[8]: += %d\n", dp1[i][j][k][l]);
                            // dp2[i + 1][j][k][l] += dp1[i][j][k][l];
                        }
                    }

                    // dp2 -> dp2
                    for (int x = 0; x < 10; x++) {
                        if (x == 3) {
#ifdef DEBUG
                            printf("[9]: += %d\n", dp2[i][j][k][l]);
#endif
                            dp2[i + 1][j + 1][k][l] += dp2[i][j][k][l];
                        } else if (x == 5) {
#ifdef DEBUG
                            printf("[10]: += %d\n", dp2[i][j][k][l]);
#endif
                            dp2[i + 1][j][k + 1][l] += dp2[i][j][k][l];
                        } else if (x == 7) {
#ifdef DEBUG
                            printf("[11]: += %d\n", dp2[i][j][k][l]);
#endif
                            dp2[i + 1][j][k][l + 1] += dp2[i][j][k][l];
                        } else {
                            // printf("[12]: += %d\n", dp2[i][j][k][l]);
                            // dp2[i + 1][j][k][l] += dp2[i][j][k][l];
                        }
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            for (int k = 1; k < 10; k++) {
#ifdef DEBUG
                if (dp1[slen][i][j][k] > 0) {
                    printf("dp1[%d][%d][%d][%d]: %d\n", slen, i, j, k, dp1[slen][i][j][k]);
                }
                if (dp2[slen][i][j][k] > 0) {
                    printf("dp2[%d][%d][%d][%d]: %d\n", slen, i, j, k, dp2[slen][i][j][k]);
                }
#endif
                ans += dp1[slen][i][j][k];
                ans += dp2[slen][i][j][k];
            }
        }
    }
    cout << ans << endl;

    return 0;
}
