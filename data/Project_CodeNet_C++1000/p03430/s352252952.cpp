#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <bitset>
#include <cassert>

using namespace std;

const int SIZE = 1 << 17;

int pointer = SIZE;
char buffer[SIZE];

char Advance() {
    if (pointer == SIZE) {
        fread(buffer, 1, SIZE, stdin);
        pointer = 0;
    }
    return buffer[pointer++];
}

int Read() {
    int answer = 0,sign = 1;
    char ch = Advance();
    while (!isdigit(ch) && ch != '-')
        ch = Advance();
    if (ch == '-') {
        ch = Advance();
        sign = -1;
    }
    while (isdigit(ch)) {
        answer = answer * 10 + ch - '0';
        ch = Advance();
    }
    return answer * sign;
}

char ReadCh() {
    char ch = Advance();
    while (!isalpha(ch))
        ch = Advance();
    return ch;
}

const int MAXN = 300;

int dp[1 + MAXN + 1][1 + MAXN + 1][1 + MAXN + 1];
char s[1 + MAXN + 1];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    scanf("%s", s + 1);
    int p, n = strlen(s + 1);
    scanf("%d", &p);
    for (int i = 1; i <= n; i++)
        for (int j = n; j > i; j--)
            for (int k = 0; k <= p; k++) {
                dp[i][j][k] = max(dp[i - 1][j][k], dp[i][j + 1][k]);
                if (s[i] == s[j])
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j + 1][k] + 1);
                else
                    if (k > 0)
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j + 1][k - 1] + 1);
            }
    int answer = 0;
    for (int i = 1; i < n; i++)
        answer = max(answer, 2 * dp[i][i + 1][p]);
    for (int i = 1; i <= n; i++)
        answer = max(answer, 2 * dp[i - 1][i + 1][p] + 1);
    printf("%d\n", answer);
    return 0;
}
