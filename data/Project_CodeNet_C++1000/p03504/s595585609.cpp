#include<iostream>
#include<iomanip>
#include<cstdio>

#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>

#include<algorithm>
#include<cmath>
#include<numeric>

using namespace std;
typedef long long ll;
template <class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template <class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}
const ll INF = 1e18+1;

int B[30][100002], S[100002];

int main() {
    int N, C; cin >> N >> C;
    vector<int> s(N), t(N), c(N);
    for (int i = 0; i < N; i++) cin >> s[i] >> t[i] >> c[i];

    for (int i = 0; i < N; i++) {
        B[c[i]-1][s[i]] += 1;
        B[c[i]-1][t[i]] += -1;
    }
    
    for (int c = 0; c < C; c++) {
        for (int i = 0; i < 1e5+1; i++) {
            if (B[c][i] == -1) {
                B[c][i+1] -= 1;
                B[c][i] += 1;
                i++;
            }
        }
    }

    for (int c = 0; c < C; c++) {
        S[0] += B[c][0];
    }
    
    for (int i = 1; i < 1e5+1; i++) {
        S[i] = S[i-1];
        for (int c = 0; c < C; c++) {
            S[i] += B[c][i];
        }
    }
    



    int res = 1;
    for (int i = 0; i < 1e5+1; i++) {
        chmax(res, S[i]);
    }
    cout << res << endl;
}
