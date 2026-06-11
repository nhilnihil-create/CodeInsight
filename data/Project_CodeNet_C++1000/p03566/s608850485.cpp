#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

signed main(){
    int n;
    cin >> n;
    int t[n], v[n];
    int T = 0;
    REP(i,n){
        cin >> t[i];
        t[i] *= 2;
        T += t[i];
    }
    REP(i,n){
        cin >> v[i];
    }
    vector<double> maxv(T + 1, INF);
    int now = 0;
    for(int i = 0; i < n; i++){
        for(int s = now; s <= now + t[i]; s++){
            maxv[s] = min(maxv[s], (double)v[i]);
        }
        now += t[i];
    }
    maxv[0] = 0.0;
    for(int s = 0; s < T; s++){
        maxv[s + 1] = min(maxv[s + 1], maxv[s] + 0.5);
    }
    maxv[T] = 0.0;
    for(int s = T; s > 0; s--){
        maxv[s - 1] = min(maxv[s - 1], maxv[s] + 0.5);
    }
    double ans = 0;
    for(int s = 0; s <= T; s++){
        ans += maxv[s];
    }
    ans /= 2.0;
    printf("%.10lf\n", ans);
    return 0;
}