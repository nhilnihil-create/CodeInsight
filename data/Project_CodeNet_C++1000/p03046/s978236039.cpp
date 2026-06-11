#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
#include <array>
#include <iomanip>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<long double> VD;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VD> VVD;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

template<typename T> void chmin(T &a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T &a, T b) { if (a < b) a = b; }

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }
#define INF 1LL<<60

int main() {
    int M, K;
    cin >> M >> K;
    if(K >= pow(2, M)) {
        cout << -1 << endl;
    } else if(M == 1 && K == 1) { 
        cout << -1 << endl;
    }else if(K == 0) {
        REP(i, pow(2, M) - 1) {
            cout << i << " " << i << " ";
        }
        cout << pow(2, M) - 1 << " " << pow(2, M) - 1 << endl;
    } else {
        REP(i, pow(2, M))
            if(i != K) cout << i << " ";
        cout << K << " ";
        FORR(i, pow(2, M) - 1, 0)
            if(i != K) cout << i << " ";
        cout << K << endl;
    }
    return 0;
}