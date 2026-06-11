#include <bits/stdc++.h>
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end() 
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define INF 1000000000
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;

    int V[N], C[N];
    REP(i, N){
        cin >> V[i];
    }
    REP(i, N){
        cin >> C[i];
    }
    
    int res = 0, pos = 0, ans = 0;
    for (int bit = 0; bit < (1<<N); ++bit) {
        //cout << bit << endl;
        res = 0;
        pos = 0;
        REP(i, N) {
            if (bit & (1<<i)) {
                res += V[i];
                pos += C[i];
            }
        }

        ans = max(ans, res - pos);
    }
    cout << ans << endl;
}