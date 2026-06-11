#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, j, n) for (int i = j; i < (int)(n); i++)
#define brep(i, n) for (int i = n; i > 0; i--)
#define BREP(i, j, n) for(int i = n; i > j; i--)
#define TEST cout << "PASS" << endl
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9 + 1e6 + 1e3 + 1;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793;

int main(){
    int n, C;
    cin >> n >> C;
    int d[500][500];
    rep(i, C) rep(j, C) cin >> d[i][j];
    
    map<int, int> mp0, mp1, mp2;
    rep(i, n) rep(j, n){
        int c;
        cin >> c;
        c--;
        if((i + j) % 3 == 0) mp0[c]++;
        else if((i + j) % 3 == 1) mp1[c]++;
        else mp2[c]++;
    }
    int ans = INF;

    rep(i, C){
        int cnta = 0;
        for(P x : mp0) cnta += d[x.first][i] * x.second;
        rep(j, C){
            if(i == j) continue;
            int cntb = 0;
            for(P x : mp1) cntb += d[x.first][j] * x.second;
            rep(k, C){
                if(j == k || k == i) continue;
                int cntc = 0;
                for(P x : mp2) cntc += d[x.first][k] * x.second;
                ans = min(ans, cnta+cntb+cntc);
            }
        }
    }
    cout << ans << endl;
}