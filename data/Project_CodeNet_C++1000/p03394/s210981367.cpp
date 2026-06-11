#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <assert.h>
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF  9223300000000000000
#define LINF2 1223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;

using namespace std;


ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b,a%b);
}

void solve()
{
    int n;
    scanf("%d", &n);
    if (n == 3) {
        printf("2 5 63\n"); return;
    }
    vector<int> z;
    int i;
    int cnt = 0;
    for (i = 1; i < 15000; i++) {
        if (gcd(i, 15000) > 1) {
            z.push_back(i);
            z.push_back(30000 - i);
            cnt++;
            if (cnt == n / 2) break;
        }
    }
    if (n % 2) z.push_back(15000);

    for (i = 0; i < (int)z.size(); i++) {
        printf("%d", z[i]);
        if (i < (int)z.size() - 1) printf(" ");
    }
    printf("\n");

    return;
}

int main(int argc, char* argv[])
{
#if 1
    solve();
#else
    int T; scanf("%d", &T);
    while(T--) {
        solve();
    }
#endif
    return 0;
}
