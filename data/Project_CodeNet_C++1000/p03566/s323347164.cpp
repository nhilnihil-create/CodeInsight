#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <iomanip>
using namespace std;
using Int = long long;
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,f,t) for(int i=f;i<t;i++)
#define P(r) do{cout<<#r": ";for(const auto &i:r){cout<<i<<" ";}cout<<endl;}while(0)
int main()
{
    int N; cin >> N;
    vector<int> T(N+1), V(N+1);
    REP(i, N) { cin >> T[i+1]; T[i+1] += T[i]; }
    REP(i, N) cin >> V[i];
    V[N] = 0;
    double ans = 0.0;
    int i = 0, v1 = 0, v2 = 0;
    for (int t = 0; t < 2*T[N]; t++, v1 = v2) {
        if (t == 2*T[i+1]) i++;
        bool slowdown = false;
        for (int k = i+1; k < N+1; k++) {
            if (v1 + (2*T[k] - t) * (-1) == 2*V[k]) {
                slowdown = true;
                break;
            }
        }
        v2 = slowdown ? v1 - 1 : v1 == 2*V[i] ? v1 : v1 + 1;
        ans += (v1 + v2) / 8.0;
    }
    cout << setprecision(20) << ans << endl;
    return 0;
}