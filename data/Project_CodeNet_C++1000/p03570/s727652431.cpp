
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b)-1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))

#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL)INF;

string s;
int a[2000000];
int n;
int ans[2000000];
map<int, int> F;

int main()
{
    //freopen("in.txt", "r", stdin);
    
    cin >> s;
    F[0] = 0;
    FOR (i,0,s.size())
    {
        if (!i) a[i] = 0;
        else a[i] = a[i-1];
        a[i] ^= (1<<(s[i]-'a'));
        //cout << a[i] << endl;
    }
    FOR (i,0,s.size())
    {
        int v = a[i];
            ans[i] = (int)s.size()+100;
            if (F.count(v)) ans[i] = F[v]+1;
            FOR (r,0,'z'-'a'+1)
            {
                int y = v^(1<<r);
                if (F.count(y)) ans[i] = min(ans[i],F[y]+1);
            }
            if (!F.count(v) || F[v] > ans[i])
                F[v] = ans[i];
        //cout << F.count(0)<<" "<<F[0]<<" "<<ans[i]<<endl;
    }
    cout << ans[s.size()-1];
}


