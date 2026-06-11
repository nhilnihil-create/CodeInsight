#include <iostream>
#include <algorithm>
#include <string>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
const int mod = (int)1e9 + 7, INF = (int)1e9;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };


int main(void) {
    int n, i, ans;
    string s;

    cin >> s;

    n = s.size();

    ans = n;
    for (i = 0; i < n - 1; i++) {
        if (s[i] != s[i + 1]) {
            ans = min(ans, max(i + 1, n - i - 1));
        }
    }

    printf("%d\n", ans);

    return 0;
}