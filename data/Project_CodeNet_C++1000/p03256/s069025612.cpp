#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>
#include <bitset>
#include <assert.h>
#include <unordered_map>
#include <fstream>
#include <time.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef pair<ll,ll> P;
typedef pair<int,int> pii;
typedef vector<P> vpl;
typedef tuple<ll,ll,ll> tapu;
#define rep(i,n) for(int i=0; i<(n); i++)
#define REP(i,a,b) for(int i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = 1<<30;
const ll linf = 1LL<<62;
const int MAX = 2020000;
ll dy[8] = {1,-1,0,0,1,-1,1,-1};
ll dx[8] = {0,0,1,-1,1,-1,-1,1};
const double pi = acos(-1);
const double eps = 1e-7;
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){
	if(a>b){
		a = b; return true;
	}
	else return false;
}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){
	if(a<b){
		a = b; return true;
	}
	else return false;
}
template<typename T> inline void print(T &a){
    rep(i,a.size()) cout << a[i] << " ";
    cout << "\n";
}
template<typename T1,typename T2> inline void print2(T1 a, T2 b){cout << a << " " << b << "\n";}
template<typename T1,typename T2,typename T3> inline void print3(T1 a, T2 b, T3 c){
	cout << a << " " << b << " " << c << "\n";
}
const int mod = 1e9 + 7;
//const int mod = 998244353;

int main(){
	ll n,m; cin >> n >> m;
    string s; cin >> s;
    vvl G(n);
    rep(i,m){
        ll u,v; cin >> u >> v; u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    queue<ll> q;
    vvl num(n,vl(2,0));
    set<ll> se;
    rep(i,n){
        for(auto v : G[i]){
            num[i][s[v]-'A']++;
        }
        if(!num[i][0] || !num[i][1]){
            q.push(i);
            se.insert(i);
        }
    }
    while(!q.empty()){
        ll u = q.front(); q.pop();
        int t = s[u] - 'A';
        for(auto v : G[u]){
            num[v][t]--;
            if(num[v][t] <= 0){
                if(se.find(v) == se.end()){
                    q.push(v);
                    se.insert(v);
                }
            }
        }
    }
    rep(i,n){
        if(se.find(i) != se.end()) continue;
        for(auto v : G[i]){
            if(se.find(v) == se.end()){
                puts("Yes");
                return 0;
            }
        }
    }
    puts("No");
}