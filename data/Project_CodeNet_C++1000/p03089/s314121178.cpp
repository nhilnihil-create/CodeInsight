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
    int n; cin >> n;
    vector<int> b;
    int tmp;
    REP(i, n) {
        cin >> tmp;
        b.push_back(tmp);
    }

    int idx = -1;
    bool changed = false;
    vector<int> res;

    while (true) {
        changed = false;
        vector<int> new_b;
        FORD(i, b.size()-1, 0) {
            if (b[i] == i+1) {
                res.push_back(i+1);
                changed = true;

                REP(j, b.size()) {
                    if (j != i) {
                        new_b.push_back(b[j]);
                    }
                }
                break;
            }
        }
        if (changed) {
            if (new_b.size() > 0) {
                b = new_b;
            } else {
                b = new_b;
                break;
            }
        } else {
            break;
        }
    }
    if (b.size() == 0) {
        FORD(i, res.size()-1, 0) {
            cout << res[i] << endl;
        }
    } else {
        cout << -1 << endl;
    }
    return 0;
}