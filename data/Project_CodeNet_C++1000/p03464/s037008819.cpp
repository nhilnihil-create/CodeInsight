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
#include <math.h>
using ll = long long;
using ld = long double;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rep3(var, min, max) for (ll (var) = (min); (var) < (max); ++(var))
#define repi3(var, min, max) for (ll (var) = (max) - 1; (var) + 1 > (min); --(var))
#define Mp(a,b) make_pair((a),(b))
#define F first
#define S second
#define CIN(s) int (s);cin>>(s);
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef vector<V> VV;
typedef vector<P> VP;
ll MOD = 1e9 + 7;
ll INF =1e18;
//ここから
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin>>n;
    V vec(n);
    rep(i,n)cin>>vec[i];
    reverse(all(vec));
    ll k_max=2;
    ll k_min=2;
    if(vec[0]!=2){
        cout<<-1<<endl;
        return 0;
    }
    rep3(i,0,n-1){
        k_max+=vec[i]-1;
        k_max=(k_max/vec[i+1])*vec[i+1];
        if(k_min%vec[i+1]!=0){
            k_min=((k_min/vec[i+1])+1)*vec[i+1];
            if(k_min>k_max){
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    k_max+=vec[n-1]-1;
    cout<<k_min<<" "<<k_max<<endl;
}

