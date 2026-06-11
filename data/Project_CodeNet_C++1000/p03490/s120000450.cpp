#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
#define INF 1007654321
#define PI 3.14159265358979
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repp(i, s, e) for(int i = (s); i <= (e); ++i)
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define FAST_IO() ios::sync_with_stdio(0); cin.tie(0)
template<typename T>
ostream& operator<<(ostream &os, const vector<T> &v) { for (auto x : v) os << x << " "; return os << "\n"; }

bool CanMakeSum(vector<int> &A, int goal) {
    int N = sz(A), M = 0;
    if(N == 0) return goal == 0;
    for(auto &x : A) M += x;
    if(abs(goal) > M) return false;
    vector<vector<bool>> DP(N, vector<bool>(2*M + 1, false));
    rep(i, N) {
        rep(j, 2*M + 1) {
        	if(i == 0) {
        		DP[i][j] = (j == M + A[i] || j == M - A[i]);
        		continue;
        	}
            if(j - A[i] < 0 && j + A[i] <= 2*M) DP[i][j] = DP[i-1][j + A[i]];
            else if(j + A[i] > 2*M && j - A[i] >= 0) DP[i][j] = DP[i-1][j - A[i]];
            else DP[i][j] = DP[i-1][j - A[i]] || DP[i-1][j + A[i]];
        }
    }
    return DP[N-1][M+goal];
}

int main() {
    FAST_IO();
    string S; cin >> S;
    S.push_back('T');
    int FX, FY; cin >> FX >> FY;
    int N = sz(S);
    vector<int> X, Y;
    int cntT = 0, cntF = 0;
    rep(i, N) {
        if(S[i] == 'T') {
            if(cntT == 0) {
                FX -= cntF;
            } else if(cntT % 2 == 0) {
                if(cntF != 0) X.push_back(cntF);
            } else {
                if(cntF != 0) Y.push_back(cntF);
            }
            cntT++;
            cntF = 0;
        }
        else {
            cntF++;
        }
    }
    if(CanMakeSum(X, FX) && CanMakeSum(Y, FY)) {
        cout << "Yes\n";
    } else cout << "No\n";
    return 0;
}

