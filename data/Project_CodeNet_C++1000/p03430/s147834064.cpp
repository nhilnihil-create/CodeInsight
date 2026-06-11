#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>
#include <bitset>
#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); i--)
#define ITER(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))

#define SZ(a) (int)a.size()
#define ALL(a) a.begin(),a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL) INF;

const int MOD = 1000 * 1000 * 1000 + 7;
const double EPS = 1e-7;


const int MAX = 303;

int DP[MAX][MAX][MAX];
char S[MAX];
int K;

int get(int l, int r, int k)
{
    if (l == r)return 1;
    if (r < l)return 0;
    int& res = DP[l][r][k];
    if (res != -1)return res;
    res = max(res, get(l+1, r, k));
    res = max(res, get(l, r - 1, k));
    if (S[l] == S[r])res = max(res, get(l + 1, r - 1, k) + 2);
    if (k < K)res = max(res, get(l+1, r-1, k+1) + 2);
    return res;
}


int main()
{

    scanf("%s", S);
    scanf("%d", &K);
    int n = strlen(S);
    FILL(DP, -1);
    cout << get(0, n-1, 0) << endl;
    
    
}
