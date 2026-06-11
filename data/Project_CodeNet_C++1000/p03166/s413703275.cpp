#include <iostream>
#include <math.h>
#include <numeric>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <queue>
#include <queue>
#include <stack> 
#include <sstream>
#include <set>
typedef  long long ll;
const int dx[8]={1,0,-1,0,1,-1,-1,1};
const int dy[8]={0,1,0,-1,1,1,-1,-1};
const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = { 0, 1, 0,-1};
const int INF = 1e9 + 5;
#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define SORT(a) sort(a.begin(),a.end())
#define REVERSE(a) reverse(a.begin(),a.end())
using namespace std;

int n,m,u,v;
int memo[110000];
bool fl[110000];
vector<int> eg[110000];


int dp(int v){
    if(fl[v]){
        return memo[v];
    }
    int ans = 0;
    for(int to: eg[v]){
        ans = max(ans, dp(to) + 1);
    }
    fl[v] = true;
    memo[v] = ans;
    return ans;
}
using namespace std;
int main(){
   

    cin >> n >> m;
    REP(i,m){
        cin >> u >> v;
        eg[u].push_back(v);
    }
    int ans = 0;
    FOR(i,1,n+1){
        ans = max(ans,dp(i));
    }

    cout << ans <<endl;

}



