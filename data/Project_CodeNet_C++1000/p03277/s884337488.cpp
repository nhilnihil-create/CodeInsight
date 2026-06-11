#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> VI;
 
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
const int mod=1e9+7;


template< typename T >
struct BinaryIndexedTree {
  vector< T > data;
  int n;
 
  BinaryIndexedTree(int sz) {
    n=sz;
    data.assign(++sz, 0);
  }
 
  T sum(int k) {
    T ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }
 
  void add(int k, T x) {
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }
 
  T sum_between(int i, int j){
      if(i>j)return 0;
      return sum(j)-sum(i-1);
  }
 
  // a[0]+...+a[ret+1] >= x
    int lower_bound(T x){
        int ret = -1;
        int k = 1;
        while(2*k <= n) k <<= 1;
        for( ;k>0; k>>=1){
            if(ret+k < n && data[ret+k] < x){
                x -= data[ret+k];
                ret += k;
            }
        }
        return ret + 1;
    }

    void print(){
      rep(i,n){
        if(i)cout<<" ";
        cout<<sum_between(i,i);
      }
      cout<<endl;
    }
};

int main(){
  int n;cin>>n;
  int a[n];rep(i,n)cin>>a[i];
  int ok=1e9+7;
  int ng=0;
  while(ok-ng>1){
    int mid=(ok+ng)/2;
    int b[n+1];b[0]=0;
    rep(i,n){
      b[i+1]=(mid-a[i]>=0?1:-1);
      b[i+1]+=b[i];
    }
    vector<int> sortedb(n+1);rep(i,n)sortedb[i+1]=b[i+1];
    sortedb[0]=0;
    sort(all(sortedb));
    sortedb.erase(unique(all(sortedb)),sortedb.end());
    BinaryIndexedTree<int> BIT(n+1);
    ll ctr=0;
    rep(i,n+1){
      int bindex=lower_bound(all(sortedb),b[i])-sortedb.begin();
      ctr+=BIT.sum(bindex-1);
      BIT.add(bindex,1);
    }
    if(ctr>1ll*n*(n+1)/4)ok=mid;
    else ng=mid;
  }
  cout<<ok<<endl;
}