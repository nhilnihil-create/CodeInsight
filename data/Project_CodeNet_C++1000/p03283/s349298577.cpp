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
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=999999999999;
int G[510][510];
int g[510][510];
vector<int> ans(MAX_N);

int main(){
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++){
        int l,r;
        cin>>l>>r;
        G[l][r]++;
    }
    // G[l][1]+G[l][2]+...+G[l][6]
    for(int i=1;i<510;i++){
        for(int j=1;j<510;j++){
            g[i][j]=G[i][j]+g[i][j-1];
        }
    }
    for(int i=0;i<q;i++){
        int s,t;
        cin>>s>>t;
        for(int j=s;j<=t;j++){
            ans[i]+=g[j][t];
        }
    }
    for(int i=0;i<q;i++) cout<<ans[i]<<endl;

}