#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<P,P> PP;
const ll MOD=998244353;
const ll MAX_N=500010;
const ll INF=100100100100100;
int dp[100100];

int solve(int now, vector<vector<int> > &G){
    if(dp[now]>0) return dp[now];
    int res=0;
    for(int to:G[now]){
        res=max(res, solve(to,G)+1);
    }
    dp[now]=res;
    return res;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> > G(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--; b--;
        G[a].push_back(b);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,solve(i,G));
    }
    cout<<ans<<endl;
}