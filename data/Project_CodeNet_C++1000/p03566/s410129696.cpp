#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <functional>
#include <map>
#include <queue>
#include <list>
#include <set>
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
using namespace std;
using ll = long long;
const int INF = 1e9 + 1;
ll MOD = 1e9+7;
ll dx[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
ll dy[9] = {-1,  0,  1,-1, 0, 1,-1, 0, 1};

int main(){    
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<double> t(N);
    vector<double> v(N);
    REP(i, N){
        cin >> t[i];
    }
    REP(i, N){
        cin >> v[i];
    }
    ll T = 0;
    REP(i, N){
        T += t[i];
    }
    
    vector<double> maxV(2*T+1, (double)INF);
    int cT = 0;
    REP(i, N){
        REP(ti, t[i]){
            int t1 = cT + ti * 2;
            int t2 = cT + ti * 2 + 1;
            maxV[t1] = min(maxV[t1], v[i]);
            maxV[t2] = min(maxV[t2], v[i]);
        }
        cT += t[i] * 2;
        maxV[cT] = min(maxV[cT], v[i]);
    }
    
    maxV[0] = maxV[T*2] = 0.0;
    REP(ti, 2*T+1){
        maxV[ti+1] = min(maxV[ti+1], maxV[ti]+0.5);
    }
    RREP(ti, 2*T+1){
        maxV[ti] = min(maxV[ti], maxV[ti+1]+0.5);
    }
    double ans = 0.0;
    REP(i, 2*T+1){
        ans += (maxV[i] + maxV[i+1]) * 0.5 / 2.0;
    }
    printf("%.8f\n", ans);
    return 0;
}
