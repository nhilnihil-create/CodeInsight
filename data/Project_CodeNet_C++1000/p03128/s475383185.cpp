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
#include<cstdio>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;

int dp[10100];

int main(){
    int N,M; cin >> N >> M;
    vector<Pi> A(M);
    rep(i,M){
        cin >> A[i].first;
    }
    rep(i,M){
        if(A[i].first == 1) A[i].second = 2;
        else if(A[i].first == 4) A[i].second = 4;
        else if(A[i].first == 6 || A[i].first == 9) A[i].second = 6;
        else if(A[i].first == 7) A[i].second = 3;
        else if(A[i].first == 8) A[i].second = 7;
        else A[i].second = 5;
    }
    rep(i,10100) dp[i] = -1;
    dp[0] = 0;
    rep(i,N+1)rep(j,M){
        if(i-A[j].second >= 0) dp[i] = max(dp[i],dp[i-A[j].second]+1);
    }
    sort(A.begin(),A.end(),greater<Pi>());
    string ans = "";
    int k = dp[N];
    while(N > 0){
        rep(i,M){
            if(N-A[i].second >= 0){
                if(dp[N-A[i].second] == k-1){
                    ans += A[i].first+'0';
                    k--;
                    N -= A[i].second;
                    break;
                }
            }
        }
    }
    cout << ans << endl;

}