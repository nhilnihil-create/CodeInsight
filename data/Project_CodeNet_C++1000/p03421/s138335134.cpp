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
const int mod = 1e9+7;
const int MAX = 510000;
const int V = 100005;
ll dy[8] = {1,0,-1,0,1,-1,1,-1};
ll dx[8] = {0,1,0,-1,1,-1,-1,1};
const double pi = acos(-1);
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T1,typename T2> inline void print2(T1 a, T2 b){cout << a << " " << b << endl;}
#define INT_MAX 1e9+7



int main(){
    ll n,a,b; cin >> n >> a >> b;
    if(a+b>n+1 || a+b<a+(n+a-1)/a) puts("-1");
    else{
        vl ans;
        if(a+b==n+1){
            rep(i,b-1) ans.push_back(n-i);
            rep(i,a) ans.push_back(i+1);
        }else{
            ll now = n;
            rep(i,b-1){
                vl v;
                do{
                    v.push_back(now);
                    now--;
                    if(now<a+1) break;
                }while((b-i-2)*a<=now-a-1);
                reverse(all(v));
                for(auto j : v) ans.push_back(j);
                v.clear();
            }
            rep(i,a) ans.push_back(i+1);
        }
        for(auto i : ans) cout << i << " ";
    } 
}
