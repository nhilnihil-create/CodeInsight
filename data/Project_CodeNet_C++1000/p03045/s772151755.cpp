#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
const int MAX_N = 100010;

int par[MAX_N];
int Rank[MAX_N];
int sizeed;

void init(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = i;
        Rank[i] = 0;
    }
    sizeed = n;
}

int find(int x) {
    if (par[x] == x) {
        return x;
    } else {
        return par[x] = find(par[x]);
    }
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    sizeed--;
    if (Rank[x] < Rank[y]) {
        par[x] = y;
    } else {
        par[y] = x;
        if (Rank[x] == Rank[y]) {
            Rank[x]++;
        }
    }
}
bool same(int x, int y) {
    return find(x) == find(y);
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    init(N);
    rep(i, M) {
        int X, Y, Z;
        cin >> X >> Y >> Z;
        X--; Y--;
        unite(X, Y);
    }
    cout << sizeed << endl;

    return 0;
}
