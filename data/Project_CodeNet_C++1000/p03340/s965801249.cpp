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

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    V vec(20);
    ll last=0;
    ll sum=0;
    V vec2(n);
    rep(i,n)cin>>vec2[i];
    rep(i,n){
        ll x=vec2[i];
        rep(j,20){
            if(x&(1<<j)){
                vec[j]++;
            }
        }
        bool h=true;
        rep(j,20){
            if(vec[j]>=2){
                h=false;
                break;
            }
        }
       /* for(auto i:vec){
            cout<<i<<" ";
        }
        cout<<endl;*/
        if(h)continue;
      //  cout<<vec2[last]<<"の続きは"<<vec2[i]<<"で重なる"<<endl;
      //  cout<<vec2[i]<<" "<<sum<<endl;
        while(1){
            ll temp=vec2[last];
            sum+=i-last;
          //  cout<<temp<<"を削除"<<endl;
            rep(j,20){
                if(temp&(1<<j)){
                    vec[j]--;
                }
            }
            last++;
          /*  for(auto i:vec){
                cout<<i<<" ";
            }
            cout<<endl;*/
            bool f=true;
            rep(j,20){
                if(vec[j]>=2){
                    f=false;
                }
            }
            if(f)break;
            
        }
        
    }
  //  ll dis=n-last;
    for(int i=last;i<n;i++){
        sum+=n-i;
    }
    cout<<sum<<endl;
}
