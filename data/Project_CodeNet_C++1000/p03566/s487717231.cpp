#include<bits/stdc++.h>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

using namespace std;

const int INF = 1e9 + 1;

int main(){
    int N;
    cin >> N;
    vector<double> t(N);
    vector<double> v(N);

    rep(i, N) {
        cin >> t[i];
    }

    rep(i, N) {
        cin >> v[i];
    }

    int T = 0;
    rep(i, N){
        T += t[i];
    }

    vector<double> maxV(2*T+1, (double)INF);

    int nowT = 0;
    rep(i, N){
        rep(ti, t[i]){
            int t1 = nowT + ti*2;
            int t2 = nowT + ti*2 + 1;
            maxV[t1] = min(maxV[t1], v[i]);
            maxV[t2] = min(maxV[t2], v[i]);
        }
        nowT += t[i]*2;
        maxV[nowT] = min(maxV[nowT], v[i]);
    }

    maxV[0] = maxV[T*2] = 0.0;

    rep(ti, 2*T+1) {
        maxV[ti+1] = min(maxV[ti+1], maxV[ti] + 0.5);
    }

    rep(ti, 2*T) {
        maxV[2*T-ti -1] = min(maxV[2*T-ti-1], maxV[2*T-ti] + 0.5);
    }

    double ans = 0.0;
    rep(i, 2*T+1) {
        ans += (maxV[i] + maxV[i+1]) * 0.5/2.0;
    }

    printf("%.4f\n", ans);
}