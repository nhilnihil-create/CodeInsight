#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <deque>
#include <queue>

#define pb push_back
#define mp make_pair
#define x first
#define y second
#define FOR(i, a, b) for(int i=a, loop=b; i<=loop; ++i)
#define REV(i, a, b) for(int i=a, loop=b; i>=loop; --i)
#define mize(a, b) a = min(a, b)
#define maxi(a, b) a = max(a, b)
#define shl(k) ((k) << 1)
using namespace std;

const int N = 105;
int n, L;
vector<pair<pair<int, int>, int> > E;

int main()
{
    ios::sync_with_stdio(); cin.tie(0);

    cin >> L;
    FOR(i, 0, 19) if ((L>>i) & 1) n = i;

    int k = 1<<n;
    FOR(i, 0, n-1){
        E.pb(mp(mp(i+1, i+2), 0));
        E.pb(mp(mp(i+1, i+2), 1<<i));
        if ((L>>i) & 1) {
            E.pb(mp(mp(i+1, n+1), k));
            k = k + (1 << i);
        }
    }

    cout << n+1 <<' ' << E.size() << '\n';
    for(auto e: E) cout << e.x.x <<' ' << e.x.y <<' ' << e.y << '\n';
}
