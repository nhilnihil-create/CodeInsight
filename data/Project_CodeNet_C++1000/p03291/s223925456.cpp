#include <iostream>
#include <queue>
#include <vector>
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#include <functional>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <map>
#include <iomanip>
#include <utility>
#include <stack>
using ll = long long;
using ld = long double;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rep3(var, min, max) for (ll (var) = (min); (var) < (max); ++(var))
#define repi3(var, min, max) for (ll (var) = (max) - 1; (var) + 1 > (min); --(var))
#define Mp(a,b) make_pair((a),(b))
#define F first
#define S second
#define CIN(s) int (s);cin>>(s);
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef vector<V> VV;
typedef vector<P> VP;
ll MOD = 1e9 + 7;
ll INF =1e18;
int main(){
    string s;
    cin>>s;
    VV dp(s.size()+1,V(4));
    dp[0][3]=1;
    rep(i,s.size()){
        rep(j,4){
            if(s[i]=='?')dp[i+1][j]+=dp[i][j]*3;
            else dp[i+1][j]+=dp[i][j];
        }
        if(s[i]=='A'){
            dp[i+1][0]+=dp[i][3];
        }
        if(s[i]=='B'){
            dp[i+1][1]+=dp[i][0];
        }
        if(s[i]=='C'){
            dp[i+1][2]+=dp[i][1];
        }
        if(s[i]=='?'){
            dp[i+1][0]+=dp[i][3];
            dp[i+1][1]+=dp[i][0];
            dp[i+1][2]+=dp[i][1];
        }
        rep(j,4){
            dp[i+1][j]%=MOD;
        }
    }
    cout<<dp[s.size()][2]<<endl;
}