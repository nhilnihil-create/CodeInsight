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
ll n;
VV gragh;
V vec;
V result;
void dfs(ll x,ll prev){
 //   cout<<x<<" "<<prev<<endl;
    rep(i,gragh[x].size()){
        if(gragh[x][i]!=prev){
            dfs(gragh[x][i],x);
        }
    }
    if(x==0)return;
    result[x] = vec[0];
   // cout<<x<<" "<<vec[0]<<endl;
    vec.erase(vec.begin());
    return;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    gragh.resize(n);
    vec.resize(n);
    result.resize(n);
    rep(i,n-1){
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        gragh[a].push_back(b);
        gragh[b].push_back(a);
    }
    rep(i, n) cin >> vec[i];
    if(n==1){
        cout << vec[0] << endl;
        return 0;
    }
    sort(all(vec));
    result[0] = vec[vec.size() - 1];
    vec.pop_back();
    ll R = 0;
    rep(i,vec.size()){
        R += vec[i];
    }
    cout << R << endl;
    dfs(0,-1);
    rep(i,n){
        cout << result[i] << " ";
    }
    cout << endl;
}
