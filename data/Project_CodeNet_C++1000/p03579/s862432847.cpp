/*
    Author:zeke
    
    pass System Test!
    GET AC!!
*/
#include <iostream>
#include <queue>
#include <vector>
#include <iostream>
#include <vector>
#include <random>
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
#include <bitset>
#include <time.h>

using ll = long long;
using ld = long double;
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define rep3(var, min, max) for (ll(var) = (min); (var) < (max); ++(var))
#define repi3(var, min, max) for (ll(var) = (max)-1; (var) + 1 > (min); --(var))
#define Mp(a, b) make_pair((a), (b))
#define F first
#define S second
#define Icin(s) \
    ll(s);      \
    cin >> (s);
#define Scin(s) \
    ll(s);      \
    cin >> (s);
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef vector<V> VV;
typedef vector<P> VP;
ll mod = 1e9 + 7;
ll MOD = 1e9 + 7;
ll INF = 1e18;
V Colors;
bool Bipartite_graph_DFS(VV &gragh,V & Colors,ll start,ll nowcolor){
    for(auto i:gragh[start]){
        if(Colors[i]!=-1){
            if(Colors[i]==nowcolor){
                return false;
            }
        }else{
            Colors[i]=1^nowcolor;
            if(!Bipartite_graph_DFS(gragh,Colors,i,1^nowcolor))return false;
        }
    }
    return true;
}
bool Bipartite_graph(ll N,VV &gragh){
    Colors.resize(N,-1);
    return Bipartite_graph_DFS(gragh,Colors,0,0);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m;
    cin>>n>>m;
    VV gragh(n);
    rep(i,m){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        gragh[a].push_back(b);
        gragh[b].push_back(a);
    }
    if(Bipartite_graph(n,gragh)){
        ll wcount=0;
        ll bcount=0;
        rep(i,n){
            if(Colors[i]){
                wcount++;
            }else{
                bcount++;
            }
        }
        cout<<wcount*bcount-m<<endl;
    }else{
        cout<<n*(n-1)/2-m<<endl;
    }
}
