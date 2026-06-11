#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, n) for(int i=0; i<(n); i++)
#define REPS(i, n) for(int i=0; i<=(n); i++)
#define FOR(i, a, b) for(int i=a; i<(b); i++)
#define FORS(i, a, b) for(int i=a; i<=(b); i++)
// for container x
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define SIZE(v) ((ll)(v).size())
#define MAX(v) *max_element(ALL(v))
#define MIN(v) *min_element(ALL(v))
#define UNIQUE(v) v.erase(unique(ALL(v)), v.end())

struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;

int main(){
    int N;
    int x[110000], y[110000], t[110000];
    cin >> N;
    x[0] = y[0] = t[0] = 0;
    REP(i, N) cin >> t[i+1] >> x[i+1] >> y[i+1];

    bool can = true;
    REP(i, N){
        int dt = t[i+1]-t[i];
        int dist = abs(x[i+1]-x[i]) + abs(y[i+1]-y[i]);
        if (dt < dist) can = false;
        if (dt%2 != dist%2) can = false;
    }

    if (can) cout << "Yes" << "\n";
    else cout << "No" << "\n";

    return 0;
}