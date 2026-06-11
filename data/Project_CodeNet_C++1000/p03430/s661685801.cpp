#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
#define int long long
#define INF 1000000000000000
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int, int> Pii;

template<typename T>
void readvec(vector<T> &a);
void readindex(vector<int> &a);



signed main(){

    string S; cin >> S;
    int N = S.size();
    int K; cin >> K;

    if(N == 1){
        cout << 1;
        return 0;
    }

    vector<mat> dp(N + 1, mat(N + 1, vec(K + 1, 0)));

    REP(i, N){
        REP(j, N){
            if(S[i] == S[N - 1 - j]){
                REP(k, K + 1) dp[i + 1][j + 1][k] = dp[i][j][k] + 1;
            }else{
                REP(k, K) dp[i + 1][j + 1][k + 1] = dp[i][j][k] + 1;
                REP(k, K + 1) dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k], max(dp[i + 1][j][k], dp[i][j + 1][k]));
            }
        }
    }

    /*
    REP(i, N + 1){
        REP(j, N + 1){
            cout << i << ", " << j << endl;
            REP(k, K + 1){
                cout << dp[i][j][k] << ",";
            }
            cout << endl;
        }
    }*/

    
    int ans = 0;
    FOR(i, 1, N){
        REP(k, K + 1){
            ans = max(dp[i][N - i][k] * 2, ans);
            ans = max(dp[i][N - i - 1][k] * 2 + 1, ans);
        }
    }

    cout << ans;
    
    return 0;
}


template<typename T>
void readvec(vector<T> &a){
    REP(i, a.size()){
        cin >> a[i];
    }
}
void readindex(vector<int> &a){
    REP(i, a.size()){
        cin >> a[i];
        a[i]--;
    }
}