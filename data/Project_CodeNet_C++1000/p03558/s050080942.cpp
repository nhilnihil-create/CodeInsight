#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>

using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> P;
typedef vector<P> vpl;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = 1<<30;
const ll linf = 1LL<<62;
const int MAX = 510000;
const int V = 100005;
ll dy[8] = {0,1,0,-1,1,-1,1,-1};
ll dx[8] = {1,0,-1,0,1,-1,-1,1};
const double pi = acos(-1);
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T1,typename T2> inline void print2(T1 a, T2 b){cout << a << " " << b << endl;}
#define INT_MAX 1<<30
const int mod = 1e9+7;



int main(){
    ll k; cin >> k;
    vector<vpl> G(k);
    rep(i,k){
        if(i<k-1) G[i].emplace_back(i+1,1);
        else G[k-1].emplace_back(0,1);
    } 
    ll tmp = 1;
    rep(i,k) G[i].emplace_back((i*10)%k,0);
    priority_queue<P,vector<P>,greater<P>> pq;
    pq.emplace(1,1);
    vl d(k,inf);
    d[1] = 1;
    while(!pq.empty()){
        P p = pq.top(); pq.pop();
        ll u = p.second;
        for(auto v : G[u]){
            if(d[v.first] > d[u] + v.second){
                d[v.first] = d[u] + v.second;
                pq.emplace(d[v.first],v.first);
            }
        }
    }
    cout << d[0] << endl;
}
