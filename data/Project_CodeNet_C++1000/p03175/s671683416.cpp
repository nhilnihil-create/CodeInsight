#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <iostream>
#include <fstream>
#include <numeric>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>
#include <set>
#include <map>
#include <functional>
#include <bitset>
#include <iomanip>
#include <stack>
#include <list>
using namespace std;
#define ll           long long
#define all(v)       (v).begin() , (v).end()
#define vi           vector <ll>
#define vii          vector <pair<ll,ll>>
#define ii           pair<ll,ll>
#define sz(v)	     ((int)((v).size()))
#define lp(i,a,b)    for(int i=a;i<b;i++)
#define pb           push_back
#define pf           push_front
#define F            first
#define S            second
#define endl         "\n"
#define IOS          ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const double PI = 3.14159265358979323846;
const ll inf=2e9,MOD=1e9+7 ,MAX=1e5+2;

vector<int>adj[MAX];
int n,dp[MAX][2];
int sol(int node,bool prev,int p){
    if(sz(adj[node])<2&&node!=1)
        return 1;
    int &ret=dp[node][prev];
    if(~ret)
        return ret;
    ret=1;
    for(auto i:adj[node]){
        if(i==p)
            continue;
        int x=sol(i,0,node);
        if(!prev)
            x+=sol(i,1,node),x%=MOD;
        ret=((ret%MOD)*(x%MOD))%MOD;
    }
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    IOS;
    cin>>n;
    lp(i,0,n-1){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    memset(dp,-1,sizeof(dp));
    cout<<(sol(1,0,0)+sol(1,1,0))%MOD;
}
