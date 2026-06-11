



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
    ll t,n,m,k,q,x,a,b,c,y,l,r;
    cin >> n;
    ll dp[1<<n];
    memset(dp,0,sizeof(dp));
    ll v[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
           cin >> v[i][j];
        }
    }
    for(int i=0; i< 1<<n ; i++){
        for(int j=0; j<n; j++){
            if(!(i&(1<<j)))continue;
            for(int k=j+1; k<n; k++){
                if(i&(1<<k))
                    dp[i]+=v[j][k];
            }
        }
    }
    for(int i=1; i<(1<<n); ++i){
        for(int j=i; j>0; j=(j-1)&i){
            dp[i]=max(dp[i],dp[j]+dp[i^j]);
        }
    }
    cout << dp[(1<<n)-1]  << el;
    return 0;
}
