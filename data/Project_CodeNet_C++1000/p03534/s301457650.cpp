#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cstdlib>
#include <stack>
#include <vector>
#define INF 0x3f3f3f3f
#define MOD 1000000009
# define FOR(i,a,n) for(register int i=a; i<=n; ++i)
# define FDR(i,a,n) for(register int i=a; i>=n; --i)
typedef long long ll;

using namespace std;
char str[100005];
int num[5];
int main()
{
    scanf("%s", str);
    int len = strlen(str);
    memset(num, 0, sizeof(num));
    FOR(i,0,len-1)
    {
        if(str[i] == 'a')num[0]++;
        if(str[i] == 'b')num[1]++;
        if(str[i] == 'c')num[2]++;
    }
    int mins = min(num[0], min(num[1], num[2]));
    num[0] -= mins;
    num[1] -= mins;
    num[2] -= mins;
    bool ok = true;
    FOR(i,0,2)
    if(num[i] >= 2)ok = false;
    if(ok)cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
