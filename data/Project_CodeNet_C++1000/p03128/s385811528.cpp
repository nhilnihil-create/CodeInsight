#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (int (i) = (int)(n) - 1 ; (i) >= m ; --(i))

#define INF 2e9
#define INF_LL 1LL<<60
#define ll long long

typedef pair<ll, ll> P;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    REP(i, m) cin >> a[i];
    
    /* 最上位から決めるためにソート */
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    vector<int> dp(n+1, -1);
    /* dp[i]: ちょうどi本作って作れる桁数の最大値 */

    int match_num[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

    dp[0] = 0;
    REPN(i, 1, n+1) {
        REP(j, m) {
            int prev = i - match_num[a[j]];
            if(prev >= 0 && dp[prev] != -1) {
                dp[i] = max(dp[i], dp[prev] + 1);   
            }
        }
    } 

    vector<int> ans;
    int ketasu = dp[n];
    int honsu = n;
    
    /* 最上位から決めていく */
    REP(i, ketasu) {
        REP(j, m) {
            if(honsu - match_num[a[j]] >= 0){
                if((dp[honsu] - 1) == dp[honsu - match_num[a[j]]]) {
                    ans.push_back(a[j]);
                    honsu -= match_num[a[j]];
                    break;
                }
            }
        }
    }

    //cout << honsu << endl;

    for(auto a: ans) cout << a;
    cout << endl;


    return 0;
}
