#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair< ll, ll > Pi;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<=(n);i++)
#define rep3(i,i0,n) for(int i=i0;i<(n);i++)
#define pb push_back
#define mod 1000000007
const ll INF = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}
#define all(x) x.begin(), x.end()
#define mp make_pair
bool compare(Pi a, Pi b) {
    if(a.first != b.first){
        return a.first < b.first;
        
    }else{
        return a.second < b.second;
    }
}


bool In_map(ll y,ll x,ll h,ll w){
    if(y<0 || x<0 || y>=h || x>=w){
        return 0;
    }else{
        return 1;
    }
}
const vector<ll> dx{1,0,-1,0};
const vector<ll> dy{0,1,0,-1};

struct UnionFind {
    vector<int> size, parents;
    UnionFind() {}
    UnionFind(int n) {  // make n trees.
        size.resize(n, 0);
        parents.resize(n, 0);
        for (int i = 0; i < n; i++) {
            makeTree(i);
        }
    }
    void makeTree(int x) {
        parents[x] = x;  // the parent of x is x
        size[x] = 1;
    }
    bool isSame(int x, int y) { return findRoot(x) == findRoot(y); }
    bool unite(int x, int y) {
        x = findRoot(x);
        y = findRoot(y);
        if (x == y) return false;
        if (size[x] > size[y]) {
            parents[y] = x;
            size[x] += size[y];
        } else {
            parents[x] = y;
            size[y] += size[x];
        }
        return true;
    }
    int findRoot(int x) {
        if (x != parents[x]) {
            parents[x] = findRoot(parents[x]);
        }
        return parents[x];
    }
    int treeSize(int x) { return size[findRoot(x)]; }
};

int main() {
    ll N,M;
    cin >> N>>M;
    
    vector<ll> A(M);
    vector<ll> B(M);
    rep(i,M){
        ll a,b;
        cin >>A[i]>>B[i];
        A[i]--;
        B[i]--;
    }
    reverse(all(A));
    reverse(all(B));
    UnionFind tree(N);
    vector<ll> ans(M);
    ans[0] = N*(N-1)/2;

    rep(i,M-1){
        
        if(!tree.isSame(A[i],B[i])){
            ans[i+1] = ans[i] - tree.treeSize(A[i])*tree.treeSize(B[i]);
            tree.unite(A[i],B[i]);
        }else{
            ans[i+1] = ans[i];
        }
        
    }
    reverse(all(ans));

    rep(i,M){
        cout <<ans[i]<<endl;
    }
    //cout << ans<<endl;
    return 0;
    

}
