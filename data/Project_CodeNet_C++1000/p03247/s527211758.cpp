#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
using namespace std;
 
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }

string dir = "RLUD";
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

int main() {
    int n;
    cin >> n;
    VL x(n), y(n);
    REP(i,n){
        cin >> x[i] >> y[i];
    }

    int p = abs(x[0] + y[0]) % 2;
    REP(i,n){
        if (abs(x[i] + y[i]) % 2 != p){
            cout << -1 << endl;
            return 0;
        }
    }

    int m = 40 ;
    VL d(m, 1);
    FOR(i,2-p,m-1){
        d[i] = 2 * d[i - 1];
    }
    cout << m << endl;
    REP(i,m) cout << d[i] << " ";
    cout << endl;
    REP(i,n){
        string s(m, 'R');
        ll xp = 0, yp = 0;
        FORR(j,m-1,0){
            ll mi = 1e18, w;
            REP(k,4){
                ll dist = abs(xp + dx[k] * d[j] - x[i]) + abs(yp + dy[k] * d[j] - y[i]);
                if (dist < mi){
                    mi = dist;
                    s[j] = dir[k];
                    w = k;
                }
            }
            xp += dx[w] * d[j];
            yp += dy[w] * d[j];
        }
        cout << s << endl;
    }
    return 0;
}
