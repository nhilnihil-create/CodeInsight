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
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=4999999996000000001;
ll black[100100];
ll white[100100];

void dfs(int now, vector<vector<int> > &G, int p) {
    black[now]=1;
    white[now]=1;
    for(int to:G[now]){
        if(to==p) continue;
        dfs(to,G,now);
        white[now]*=white[to]+black[to];
        black[now]*=white[to];
        white[now]%=MOD;
        black[now]%=MOD;
    }
}

int main(){
    int n;
    cin>>n;
    vector<vector<int> > G(n);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0,G,-1);
    ll ans=white[0]+black[0];
    ans%=MOD;
    cout<<ans<<endl;
}