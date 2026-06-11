#include <bits/stdc++.h>

using namespace std;
 
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;

ll MOD = 1000000007;
int MAX_COLORS = 200000;

int main(){
    int N;
    cin >> N;
    
    vi C(N);

    for(int i=0;i<N;i++) cin >> C[i];

    //uniqify
    vi D;
    D.push_back(C[0]);
    for(int i=1;i<N;i++) {
        if(C[i]!=C[i-1]) D.push_back(C[i]);
    }
 
    N = D.size();

    vll sums(MAX_COLORS+1, 0);
    vll dp(N+1, 0);
    dp[0] = 1;
    for(int i=1;i<=N;i++) {
        int c = D[i-1];
        sums[c] += dp[i-1];
        sums[c] %= MOD;
        dp[i] = sums[c];
    }

    cout << dp[N] << endl;

    return 0;
}
