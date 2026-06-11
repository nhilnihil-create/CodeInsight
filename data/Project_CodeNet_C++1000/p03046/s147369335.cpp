#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define Rep(i,n) for(int i = 1; i <= n; i++)
#define sz(x) int(x.size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YesorNo(a) printf(a ? "Yes\n" : "No\n")
#define endl '\n'
#define fi first
#define se second
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
template<class T> using V = vector<T>;
const int dx[] = {0,1,0,-1,1,1,-1,-1};
const int dy[] = {1,0,-1,0,1,-1,-1,1};
const int inf = (1<<30)-1;
const ll infll = (1LL<<62)-1;
ll ceil(const ll &a, const ll &b){return ((a)+(b)-1)/b;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



int main(){
    int m, k;
    cin >> m >> k;
    if(m == 0) {
        if(k == 0) cout << "0 0" << endl;
        else cout << -1 << endl;
        return 0;
    }
    if(m == 1) {
        if(k == 0) cout << "0 0 1 1" << endl;
        else cout << -1 << endl;
        return 0;
    }
    if((1<<m)-1 < k) {
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < (1<<m); i++) {
        if(i != k) cout << i << " ";
    }
    cout << k << " ";
    for(int i = (1<<m)-1; i >= 0; i--) {
        if(i != k) cout << i << " ";
    }
    cout << k <<  endl;
}
