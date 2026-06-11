#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
template< typename T >
struct BinaryIndexedTree {
  vector< T > data;

  BinaryIndexedTree(int sz) {
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
};


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  int ub = 1e9+2;
  int lb = 0;
  while(ub-lb>1){
    int mid = (ub+lb)/2;
    vector<int> b(n);
    rep(i,n){
      if(a[i]<mid) b[i] = 0;
      else b[i] = 1;
    }
    vector<int> sum(n+1);
    sum[0] = 0;
    rep(i,n) sum[i+1] = sum[i] + b[i];
    rep(i,n+1) sum[i] = sum[i]*2 - i + n;
    BinaryIndexedTree<int> bito(n*3+10);
    BinaryIndexedTree<int> bite(n*3+10);
    ll cnt = 0;
    rep(i,n+1){
      // cout << sum[i] << endl;
      if(i%2==0){
        cnt += bite.sum(sum[i]);
        cnt += bito.sum(max(0,sum[i]-1));
        bite.add(sum[i],1);
      }
      else{
        cnt += bite.sum(max(0,sum[i]-1));
        cnt += bito.sum(sum[i]);
        bito.add(sum[i],1);
      }
    }
    // cout << mid <<" " << cnt << endl;
    if(cnt>=(n*(n+1)/2+1)/2) lb = mid;
    else ub = mid;
  }
  cout << lb << endl;
   

  
  return 0;
    

}
