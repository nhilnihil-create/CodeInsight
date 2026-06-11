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
#include <time.h>
#pragma warning(disable:4996) 

typedef long long ll;
typedef unsigned long long ull;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF  9223300000000000000
#define LINF2 1223300000000000000
#define LINF3 1000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;

using namespace std;


void solve()
{
    int L;
    scanf("%d", &L);
    int curr = 0;
    int val = 1;
    int i;

    vector<int> a;
    while (L) {
        a.push_back(L % 2);
        L /= 2;
    }

    a.pop_back();
    vector<pair<pair<int, int>, int> > v;
    while (!a.empty()) {
        int tmp = a.back();
        a.pop_back();
        curr++;
        val *= 2;
        if (tmp == 0) {
            int siz = v.size();
            for (i = 0; i < siz; i++) {
                v[i].second *= 2;
            }
            v.push_back(make_pair(make_pair(curr - 1, curr), 0));
            v.push_back(make_pair(make_pair(curr - 1, curr), 1));
        }
        else {
            int siz = v.size();
            for (i = 0; i < siz; i++) {
                v[i].second *= 2;
            }
            v.push_back(make_pair(make_pair(curr - 1, curr), 0));
            v.push_back(make_pair(make_pair(curr - 1, curr), 1));
            v.push_back(make_pair(make_pair(0, curr), val));
        }
        val += tmp;
    }

    int m = (int)v.size();
    int n = curr+1;
    printf("%d %d\n", n, m);
    for (i = 0; i < m; i++) {
        printf("%d %d %d\n", v[i].first.first + 1, v[i].first.second + 1, v[i].second);
    }

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
