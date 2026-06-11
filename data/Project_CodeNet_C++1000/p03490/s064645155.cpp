#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <cassert>
#include <numeric>
#include <functional>
#include <cassert>
//#include <numeric>
#pragma warning(disable:4996) 
 
typedef long long ll;
typedef unsigned long long ull;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF  9223300000000000000
#define LINF2 1223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;

using namespace std;

char str[8005];

int dp0[4005][8005];
int dp1[4005][8005];

void solve()
{
    scanf("%s", str);
    int n = strlen(str);
    int x, y;
    scanf("%d%d", &x, &y);

    vector<int> v;
    int cnt = 0;
    int i;
    for (i = 0; i < n; i++) {
        if (str[i] == 'F') {
            cnt++;
        }
        else {
            v.push_back(cnt);
            cnt = 0;
        }
    }
    v.push_back(cnt);
    int siz = (int)v.size();
    
    vector<int> v0, v1;
    int sum0 = 0, sum1 = 0;
    for (i = 0; i < siz; i++) {
        if (i%2==0) {
            if(i!=0) v0.push_back(v[i]);
            sum0 += v[i];
        }
        else {
            v1.push_back(v[i]);
            sum1 += v[i];
        }
    }
    int tmp0=sum0 - x;
    if (tmp0 % 2 || tmp0<0) {
        printf("No\n"); return;
    }
    x = tmp0 / 2;

    int tmp1 = sum1 - y;
    if (tmp1 % 2 || tmp1<0) {
        printf("No\n"); return;
    }
    y = tmp1 / 2;

    int siz0 = (int)v0.size();
    int j;
    dp0[0][0] = 1;
    for (i = 0; i <siz0; i++) {
        for (j = 0; j <= n; j++) {
            if (dp0[i][j]) {
                {
                    int j2 = j;
                    if(j2<=n) dp0[i + 1][j2] = 1;
                }
                {
                    int j2 = j + v0[i];
                    if(j2<=n) dp0[i + 1][j2] = 1;
                }
            }
        }
    }
    if (dp0[siz0][x] == 0) {
        printf("No\n"); return;
    }

    int siz1 = (int)v1.size();
    dp1[0][0] = 1;
    for (i = 0; i < siz1; i++) {
        for (j = 0; j <= n; j++) {
            if (dp1[i][j]) {
                {
                    int j2 = j;
                    if(j2<=n) dp1[i + 1][j2] = 1;
                }
                {
                    int j2 = j + v1[i];
                    if(j2<=n) dp1[i + 1][j2] = 1;
                }
            }
        }
    }
    if (dp1[siz1][y] == 0) {
        printf("No\n"); return;
    }
    printf("Yes\n");


    return;
}

int main(int argc, char* argv[])
{
#if 1
    solve();
#else
    int T;
    scanf("%d", &T);
    int t;
    for(t=0; t<T; t++) {
        //printf("Case #%d: ", t+1);
        solve();
    }
#endif
    return 0;
}

