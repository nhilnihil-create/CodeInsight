#include <stdio.h>
#include <vector>
#include <stack>
#include <functional>
#include <numeric>
#include <complex>
#include <queue>
#include <map>
#include <unordered_map>
#include <list>
#include <set>
#include <unordered_set>
#include <assert.h>
#include <cstring>
#include <sstream>
#include <string>
#include <algorithm>
#include <iostream>
 
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define X first
#define Y second
#define pb(x) push_back(x)
#define FOR(k, n) for (int k = 0; k < n; k++)
#define FORN(k, s, n) for (int k = s; k < n; k++)
#define debug(x) printf("x = %d\n", x);
#define debug2(x, y) printf("x = %d, y = %d\n", x, y);
#define debug3(x, y, z) printf("x = %d, y = %d, z = %d\n", x, y, z);
#define debug4(x, y, z, t) printf("x = %d, y = %d, z = %d, t = %d\n", x, y, z, t);
 
#pragma warning(disable : 6031)
#pragma warning(disable : 4101)
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef complex<double> cd;
 
const int INF = 1e9;
const long long LINF = 1e18;
const double PI = acos(-1);
 
// Solution

const int MAXN = 100005;

ll n, k, sum, best, uniq, V[MAXN];
pair<ll, ll> A[MAXN];
priority_queue<ll, vector<ll>, greater<ll>> Q;

int main() {
    scanf("%lld%lld", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &A[i].Y, &A[i].X);
    }

    sort(A, A + n, greater<pair<ll, ll>>());

    for (int i = 0; i < n; i++) {
        if (i >= k) {
            if (Q.empty()) {
                break;
            }

            sum -= Q.top();
            Q.pop();
        }

        if (!V[A[i].Y]) {
            V[A[i].Y] = true;
            uniq++;
        } else {
            Q.push(A[i].X);
        }

        sum += A[i].X;
        best = max(best, sum + uniq * uniq);
    }

    printf("%lld\n", best);

    return 0;
}