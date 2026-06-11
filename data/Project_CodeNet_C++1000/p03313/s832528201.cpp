#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
//#define MOD 1000000007
#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;

Pi dp[1<<18];

int main(){
    int N; cin >> N;
    vector<int> A(1<<N);
    rep(i,1<<N){
        cin >> A[i];
        dp[i] = {A[i],-1};
    }

    rep(i,N)rep(j,1<<N){
        if(j>>i&1){
            if(dp[j^(1<<i)].first > dp[j].first){
                dp[j].second = max(dp[j].first,dp[j^(1<<i)].second);
                dp[j].first = dp[j^(1<<i)].first;
            }
            else dp[j].second = max(dp[j].second,dp[j^(1<<i)].first);
        }
    }

    int ans = -1;
    repr(i,1,1<<N){
        ans = max(ans,dp[i].first+dp[i].second);
        cout << ans << endl;
    }

}
    

