#include <bits/stdc++.h>
using namespace std;
#define SELECTER(_1, _2, _3, SELECT, ...) SELECT
#define REP1(i, n) for(int (i)=0; (i)<(n); (i)++)
#define REP2(i, a, b) for(int (i)=(a); (i)<(b); (i)++)
#define REP(...) SELECTER(__VA_ARGS__, REP2, REP1,) (__VA_ARGS__)

template <class T> ostream& operator<<(ostream& os, const vector<T>& v){ os << "{"; for(size_t i=0; i<v.size(); i++) os << v[i] << (i+1==v.size() ? "" : ", "); os << "}"; return os; }
template <class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p){ return os << "{" << p.first << ", " << p.second << "}"; }

int main(){
    int N;
    cin >> N;
    vector<tuple<int, int, int, int>> A(N);
    REP(i, N){
        int w, s, v;
        cin >> w >> s >> v;
        A[i] = make_tuple(w+s, w, s, v);
    }
    sort(A.begin(), A.end());
    vector<vector<long long>> dp(N+1, vector<long long>(20001));
    REP(i, N) {
        long long ws, w, s, v;
        tie(ws, w, s, v) = A[i];
        dp[i+1] = dp[i];
        REP(j, min(s+1, 20001-w))
            dp[i+1][j+w] = max(dp[i+1][j+w], dp[i][j] + v);
    }
    long long ans = *max_element(dp[N].begin(), dp[N].end());
    cout << ans << endl;
    return 0;
}