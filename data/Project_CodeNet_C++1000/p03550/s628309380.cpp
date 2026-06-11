#include <bits/stdc++.h>
using namespace std;

using int32 = int_fast32_t;
using int64 = int_fast64_t;

const int32 INF = 1e9;
const int32 MOD = 1e9+7;
const int64 LLINF = 1e18;

#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define ANS(n) cout << (n) << "\n"
#define REP(i,n) for(int64 i=0;i<(n);++i)
#define FOR(i,a,b) for(int32 i=(a);i<(b);i++)
#define FORR(i,a,b) for(int64 i=(a);i>=(b);i--)
#define ALL(obj) (obj).begin(),(obj).end()
#define pii pair<int32,int32>
#define pll pair<int64,int64>
#define pb(a) push_back(a)
#define mp make_pair

int32 n, z, w;
vector<int32> a;
vector<map<int32,int32>> memo1;
vector<map<int32,int32>> memo2;

int32 dfs(int32 x, int32 y, bool turn, int32 top){
    if(top == n)return abs(x - y);
    if(turn){
        if(memo1[top].find(y) != memo1[top].end())return memo1[top][y];
        int32 ret = -1;
        FOR(i,top,n){
            ret = max(ret, dfs(a[i],y,false,i+1));
        }
        return memo1[top][y] = ret;
    }else{
        if(memo2[top].find(x) != memo2[top].end())return memo2[top][x];
        int32 ret = INF;
        FOR(i,top,n){
            ret = min(ret, dfs(x,a[i],true,i+1));
        }
        return memo2[top][x] = ret;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> z >> w;
    a = vector<int32>(n);
    memo1 = memo2 = vector<map<int32,int32>>(n);
    REP(i,n)cin >> a[i];
    ANS(dfs(z, w, true, 0));
    return 0;
}