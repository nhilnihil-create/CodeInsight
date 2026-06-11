#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair < int, int > PII;
typedef pair < LL, LL > PLL;

const int INF = 1000000007;
const LL INFLL = 1000000000000000007;

#define st first
#define nd second
#define pb push_back
#define _boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// ***************************** CODE ***************************** //

const int MAX = (1 << 16) + 7;
const int SIZE = 17;

LL tab[SIZE][SIZE];
LL dp[MAX], Cost[MAX];

LL cost(LL mask)
{
    LL res = 0;
    for(int i = 0; i < SIZE; i++)
        if((mask&(1<<i)) == (1<<i))
            for(int j = i+1; j < SIZE; j++)
                if((mask&(1<<j)) == (1<<j))
                    res += tab[i][j];

    return res;
}

int main() {
    _boost;

    int n;  cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> tab[i][j];

    for(int i = 0; i < MAX; i++)
        Cost[i] = cost(i);

    for(int i = 0; i < MAX; i++)
        for(int j = i; j >= 0; j = ((j-1)&i))
        {
            dp[i] = max(dp[i], (Cost[j] + dp[i^j]));
            if(j == 0) break;
        }

    cout << dp[((1<<n)-1)];
    return 0;
}
