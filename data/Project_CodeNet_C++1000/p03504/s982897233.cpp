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
bool judge(ll k,V vec,ll &a,ll &b){
    rep(i,vec.size()){
        vec[i] -= b*k;
    }
    sort(all(vec), greater<ll>());
    ll cnt = 0;
    rep(i,vec.size()){
        if(vec[i]<=0){
            break;
        }
        if(vec[i]%a==0){
            cnt += vec[i] / a;
        }else{
            cnt += vec[i] / a + 1;
        }
    }
    return cnt <= k;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,c;
    cin >> n >> c;
    vector<VP> vec(c);
    rep(i,n){
        ll s,t,c;
        cin >> s >> t >> c;
        c--;
        vec[c].push_back({s, t});
    }
    V res(1e5+1);
    rep(i,c){
        V temp(1e5+1);
        rep(j,vec[i].size()){
            rep3(k,vec[i][j].F,vec[i][j].S+1){
                temp[k] = 1;
            }
        }
        rep(i,1e5+1){
            if(temp[i]){
                res[i]++;
            }
        }
    }
    ll Res = 0;
    rep(i,1e5+1){
        chmax(Res, res[i]);
      //  cout<<res[i]<<" ";
    }
  //  cout<<endl;
    cout << Res << endl;
}
