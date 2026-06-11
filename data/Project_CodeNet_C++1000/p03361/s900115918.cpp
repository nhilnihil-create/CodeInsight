#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<iterator>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define D()
#define INF 1000000000000
#define MOD 10000007
#define MAXR 100000
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define INITA(a,i,j,v) for(ll k=i;k<=j;k++){a[k]=v;}

int main() {
    int h, w; cin >> h >> w;
    char a[100][100];
    REP(i, h) {
        REP(j, w) {
            cin >> a[i][j];
        }
    }
    vector<int> di = {-1, 1, 0, 0};
    vector<int> dj = {0, 0, -1, 1};
    REP(i, h) {
        REP(j, w) {
            if (a[i][j] != '#') {
                continue;
            }

            bool ok = false;
            REP(k, 4) {
                if ((0 <= i+di[k]) && (i+di[k] < h) && (0 <= j+dj[k]) && (j+dj[k] < w)) {
                    if (a[i+di[k]][j+dj[k]] == '#') {
                        ok = true;
                    }
                }
            }
            if (!ok) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}