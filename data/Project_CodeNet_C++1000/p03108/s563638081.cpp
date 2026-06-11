#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
typedef long long ll;
const ll INF = 1e+18;
int N,M;

struct UnionFind {
  vector< int > data;
 
  UnionFind(int sz) {
    data.assign(sz, -1);
  }
 
  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }
 
  int find(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }
 
  int size(int k) {
    return (-data[find(k)]);
  }
};

int main(){
    cin >> N >> M;
    vector<int> A(M),B(M);
    rep(i,M){
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
    }
        
    UnionFind uf(N);
    ll cnt=0;
    ll a,b;
    vector<ll> ans(M);
    for(int i=M-1;i>=0;i--){
        ans[i]=((ll)N*(ll)(N-1))/2-cnt;
        a=uf.size(A[i]);
        b=uf.size(B[i]);
        if(uf.unite(A[i],B[i])) cnt+=a*b;
        
    }   
    rep(i,M) cout << ans[i] << endl;
}
