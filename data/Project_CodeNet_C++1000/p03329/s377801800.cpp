#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

typedef long long ll;
typedef pair<ll, ll> P;

const int mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 11


int main()
{
    int n; cin >> n;
    vector<int> six;
    vector<int> nine;
    int tmp = 6; 
    while(tmp <= 100005){
        six.push_back(tmp);
        tmp *= 6;
    }
    tmp = 9;
    while(tmp <= 100005){
        nine.push_back(tmp);
        tmp *= 9;
    }
    int dp[n+1];
    dp[0] = 0;
    for(int i = 1 ; i <= n; i++){
        dp[i] = dp[i-1]+1;
        for(auto s : six){
            if(i - s >= 0){
                dp[i] = min(dp[i],dp[i-s]+1);
            }
        }
        for(auto x : nine){
            if(i - x >= 0){
                dp[i] = min(dp[i],dp[i-x]+1);
            }
        }
    }
    cout << dp[n] << endl;
}