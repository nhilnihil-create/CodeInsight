#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <cmath>
#include <cstdio>

using namespace std;

typedef long long ll;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)

int N, A, B, C, D;
string S;

bool judge(int start, int goal)
{
    bool dp[N + 1];
    dp[0] = true;
    dp[start] = true;
    dp[start + 1] = (S[start] == '.')? true : false;

    FOR(i, start + 1, goal) {
        if (S[i] == '#') dp[i + 1] = false;
        else {
            if (dp[i] || dp[i - 1]) dp[i + 1] = true;
            else dp[i + 1] = false;
        }
    }
    return dp[goal];
}

int main(int argc, char **argv)
{
    cin >> N >> A >> B >> C >> D >> S;

    if (C < D) {
        bool fa = judge(A, C);
        bool fb = judge(B, D);
        if (fa && fb) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else {
        bool fb = judge(B, D);

        bool f = true;
        FOR(i, B - 2, D - 1) {
            if (S[i] == '.' && S[i + 1] == '.' && S[i + 2] == '.') {
                S[i + 1] = '#';
                f = false;
                break;
            }
        }
        if (f) {
            cout << "No" << endl;
        }
        else {
            bool fa = judge(A, C);
            if (fa && fb) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}
