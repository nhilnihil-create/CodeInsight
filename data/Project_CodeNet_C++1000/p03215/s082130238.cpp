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
ll MOD = 1e9 + 7;
ll INF = 1e18;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    V vec;
    vec.push_back(0);
    rep3(i,1,n + 1){
        ll x;
        cin>>x;
        vec.push_back(x);
    }
   // sort(all(vec));
    rep3(i,1,n + 1) vec[i] += vec[i - 1];
    V sum;
    rep(i, n)
    {
        rep3(j, i + 1, n + 1)
        {
            sum.push_back(vec[j] - vec[i]);
        }
    }
  //  sort(all(sum));
    ll res = 0;
    vector<bool> have(sum.size(),true);
    for (ll t = pow(2, 60); t >= 1; t /= 2)
    {
        ll temp=0;
        V kesu;
        rep(j,sum.size()){
            if((sum[j]&t)&&(have[j])){
               temp++; 
            }else{
                kesu.push_back(j);
            }
        }
        
        if(temp>=k){
            res+=t;
            rep(j,kesu.size()){
                have[kesu[j]]=false;
            }
        }
    }
    cout << res << endl;
}
