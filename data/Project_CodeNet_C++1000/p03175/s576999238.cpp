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

P dfs(int now, vector<vector<int> > &G, vector<bool> &visited) {
    visited[now]=true;
    ll w=1, b=1;
    for(int to:G[now]){
        if(visited[to]) continue;
        P p=dfs(to,G,visited);
        w*=p.first+p.second;
        b*=p.first;
        w%=MOD;
        b%=MOD;
    }
    return P(w,b);
    
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
    vector<bool> visited(n,false);
    P ans=dfs(0,G,visited);
    ll cc=ans.first+ans.second;
    cc%=MOD;
    cout<<cc<<endl;
}