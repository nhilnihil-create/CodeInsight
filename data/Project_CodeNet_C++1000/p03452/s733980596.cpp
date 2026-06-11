#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
 
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

struct WUnion {
  vector< int > data;
  vector< int > diff_weight;
 
  WUnion(int sz) {
    data.assign(sz, -1);
    diff_weight.assign(sz,0);
  }
 
  bool unite(int x, int y, int w) {
    w+=weight(x);w-=weight(y);
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y),w=-w;
    data[x] += data[y];
    data[y] = x;
    diff_weight[y]=w;
    return (true);
  }
 
  int find(int k) {
    if(data[k] < 0) return (k);
    else{
        int r=find(data[k]);
        diff_weight[k]+=diff_weight[data[k]];
        return (data[k] = find(data[k]));
    }
  }
 
  int size(int k) {
    return (-data[find(k)]);
  }
  int weight(int k){
      find(k);
      return diff_weight[k];
  }
  int diff(int x, int y){
      return weight(y)-weight(x);
  }
};

int main(){
    int n,m;cin>>n>>m;
    WUnion wu(n);
    rep(i,m){
        int l,r,d;cin>>l>>r>>d;
        --l;--r;
        if(wu.find(l)==wu.find(r)&&wu.diff(l,r)!=d){
            cout<<"No"<<endl;
            exit(0);
        }
        else{
            wu.unite(l,r,d);
        }
    }
    cout<<"Yes"<<endl;
}