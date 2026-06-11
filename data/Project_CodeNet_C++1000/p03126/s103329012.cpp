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
    int N, M;
    cin >> N >> M;

    vector<int> K(N);
    vector<vector<int>> A(N);

    REP(i, N){
        cin >> K[i];
        REP(j, K[i]){
            int a;
            cin >> a;
            A[i].push_back(a);
        }
    }

    int res, ans = 0;
    FOR(s, 1, M){
        res = 0;
        REP(i, N){
            REP(j, SIZE(A[i])){
                if (s == A[i][j]){
                    res++;
                }
            }
        }
        if (res == N){
            ans++;
        }
    }
    cout << ans << endl;
}