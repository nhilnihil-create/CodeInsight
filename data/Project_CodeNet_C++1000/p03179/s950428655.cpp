




#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
#include <numeric>
#include <deque>
#include <cstring>
#include <iterator>
#include <map>
#include <cstdlib>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <complex>
#include <bitset>
#include <chrono>
#include <random>
#include <assert.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define eb emplace_back
#define el '\n'
typedef  long long  ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<bool> vb;


const int mod=1000000007;
//const int mod=998244353;





int main()
{   ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll t,n,m,k,q,x,a,b,c,d,y,l,r;
    cin >> n;
    string s;
    cin >> s;
    vvll dp(n+1,vll(n+1,0));
    dp[0][1]=1;
    for(int i=1; i<=n; i++){
        dp[0][i]+=dp[0][i-1];
    }
    for(int i=0; i<n-1; i++){
        if(s[i]=='>'){
            for(int j=1; j<=i+2; j++){
                dp[i+1][j]=dp[i][n]-dp[i][j-1];
            }
        }
        else{
            for(int j=1; j<=i+2; j++){
                dp[i+1][j]=dp[i][j-1];
            }
        }
        for(int j=1; j<=n; j++){
            dp[i+1][j]+=dp[i+1][j-1];
            dp[i+1][j]%=mod;
        }
    }
    cout << (dp[n-1][n]+mod)%mod << el;
    return 0;
}
