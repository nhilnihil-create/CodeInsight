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
    ll n; cin >> n;
    vl ans;
    if(n==3){
        puts("2 5 63");
        return 0;
    }
    if(n<=15000){
        if(n%3==0){
            rep(i,4) ans.push_back(i*6+3);
            REP(i,1,n-3) ans.push_back(i*2);
        }else{
            ans.push_back(3); ans.push_back(9);
            REP(i,1,n-1) ans.push_back(i*2);
        }
    }else{
        if(n%2==0){
            REP(i,1,15001) ans.push_back(i*2);
            rep(i,n-15000) ans.push_back(i*6+3);
        }else{
            REP(i,1,15000) ans.push_back(i*2);
            rep(i,n-14999) ans.push_back(i*6+3);
        }
    }
    for(auto i : ans) cout << i << " ";
    cout << endl;
}
