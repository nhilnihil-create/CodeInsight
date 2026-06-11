#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rrep(i,n) for (int i = n-1; i >= 0; i--)
#define rep2(i,s,n) for (int i = s; i < n; ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define tmax(a,b,c) max(a,max(b,c))
#define tmin(a,b,c) min(a,min(b,c))
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vs vector<string>
#define vc vector<char>
#define vb vector<bool>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using LP = pair<ll,ll>;
inline void Yes(bool b) { cout << (b ? "Yes" : "No") << endl; }
template<class T> inline bool chmin(T& a,T b) {if(a > b){a = b; return true;} return false;}
template<class T> inline bool chmax(T& a,T b) {if(a < b){a = b; return true;} return false;}
template<class T> inline void operator>>(istream& is,vector<T>& v) { for(int& i : v){ is>>i; } }
template<class T> inline void operator<<(ostream& os,const vector<T>& v) { for(int i : v){ os<<i<<" "; } os<<endl; }
const int inf = 1001001001;
const ll linf = 1001001001001001001;
const int mod = 1000000007;

template<typename T>
struct weight_unionfind {
    vi par,rank;
    vector<T> diff_weight;
    weight_unionfind(int n):par(n,-1),rank(n,0),diff_weight(n,0) {}
    int root(int x) {
        if(par[x] < 0) return x;
        else {
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }
    T weight(int x) {
        root(x);
        return diff_weight[x];
    }
    bool same(int x,int y) {
        return root(x) == root(y);
    }
    bool unite(int x,int y,T w) {
        w += weight(x); w -= weight(y);
        x = root(x); y = root(y);
        if(x == y) return false;
        if(rank[x] < rank[y]) swap(x,y),w = -w;
        if(rank[x] == rank[y]) rank[x]++;
        par[x] += par[y];
        par[y] = x;
        diff_weight[y] = w;
        return true;
    }
    T diff(int x,int y) {
        return weight(y)-weight(x);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,m;
    cin >> n >> m;
    weight_unionfind<int> uf(n);
    rep(_,m) {
        int l,r,d;
        cin >> l >> r >> d;
        l--; r--;
        if(uf.same(l,r)) {
            if(uf.diff(l,r) != d) {
                cout << "No" << endl;
                return 0;
            }
        } else {
            uf.unite(l,r,d);
        }
    }
    cout << "Yes" << endl;
}
