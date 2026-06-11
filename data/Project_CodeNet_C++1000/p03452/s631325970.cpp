#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
#include <complex> // complex<double> a(1.2 , 2.3);// real(): 1.2, imag()2.3
using namespace std;

#define MOD 1000000007
#define ll long long
#define ld long double
#define FOR(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define rep(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define rmsame(a) sort(all(a)),a.erase(unique(all(a)), a.end())
#define rmvector(a,b) rep(i,a.size())rep(j,b.size())if(a[i]==b[j]){a.erase(a.begin()+i);i--;break;}
#define pq_pair_tB priority_queue <pair<ll,ll>, vector<pair<ll,ll> > , greater<pair<ll,ll> > > 
#define pq_pair_ts priority_queue <pair<ll,ll> > //第二成分の大きさが関係ない
template<typename X> bool exist(vector<X> vec, X item){return find(all(vec), item)!=vec.end();}
ll gcd(ll a, ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}

struct UnionFind {
    
    vector < int > node;
    UnionFind(int n) : node(n, -1) {}
    
    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x != y) {
            if (node[y] < node[x]) swap(x, y);
            node[x] += node[y];
            node[y] = x;
        }
        return x != y;
    }
    
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    
    int root(int x) {
        return node[x] < 0 ? x : node[x] = root(node[x]);
    }
    
    int size(int x) {
        return -node[root(x)];
    }
    
};
/*
 usage:
 
 初期化:
 UnionFind  UF(N);//ノードの数
 unite(x,y);// xとyノード連結
 same(a,b);// aとbが同じ所属かどうかを判別
 root(a); //aのルートのノードを計算
 */

ll N , M ;
vector<ll> rut;

map<ll, vector<pair<ll,ll> > >to;
ll ans[100005];


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    rep(i,100005) ans[i] = -1e18;// initialize

    cin >> N >> M ;

    
    UnionFind UF(N);
    
    rep(i,M){
        ll l, r , d;
        cin >> l >> r >> d;
        l--; r--;
        
        UF.unite(l,r);
        to[l].pb(mp(r, d));
        to[r].pb(mp(l, d*(-1)));
    }
    
    rep(i,N){
        rut.pb(UF.root(i));
    }
    rmsame(rut);

    rep(i, rut.size()){
        ans[rut[i]] = 0;
    }
    
    while(rut.size() != 0){
        ll siz = rut.size();

        rep(i,siz){
            ll now = rut[0];
            rep(j, to[now].size()){
                ll next = to[now][j].first;
                ll dis = to[now][j].second;
                if(ans[next] == -1e18){
                    ans[next] = ans[now] + dis;
                    rut.pb(next);
                }
                else{
                    if(ans[next] != ans[now] + dis){
                        cout << "No" << endl;
                        return 0;
                    }
                }
            }
            rut.erase(rut.begin());
        }
    }
    cout << "Yes" << endl;
    
    //cout << fixed << setprecision(16) << ans << endl;
    return 0;
}
