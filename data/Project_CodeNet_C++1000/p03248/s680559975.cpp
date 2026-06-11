#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
const int mod = (int)1e9 + 7, INF = (int)1e9;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };


int main(void) {
    int n, i, fv;
    string s;

    cin >> s;

    n = s.size();

    for (i = 0; i < n - 1; i++) {
        if (s[i] != s[n - i - 2]) {
            printf("-1\n");
            return 0;
        }
    }

    if (s[0] == '0' || s[n - 1] == '1') {
        printf("-1\n");
        return 0;
    }

    fv = 1;
    for (i = 2; i <= n / 2 + 1; i++) {
        printf("%d %d\n", fv, i);
        if (s[i - 2] == '1') {
            fv = i;
        }
    }

    if (s[n / 2 - 1] == '1') {
        fv = n / 2 + 1;
    }

    for (i = n / 2 + 2; i <= n; i++) {
        printf("%d %d\n", fv, i);
    }

    return 0;
}