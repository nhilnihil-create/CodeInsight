#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second
 
const int mx=100010;
const ll mod=1e9+7;


int main(){
  int h,w,d;
  cin >> h >> w >> d;
  vector<P> a(100000);
  rep(i,h)rep(j,w){
    int k; cin >> k;
    a[k].F=j+1;
    a[k].S=i+1;
  }

  vector<ll> sum(100000,0);
  for(int i=d+1; i<=h*w; i++){
    sum[i] = sum[i-d] + abs(a[i].F-a[i-d].F) + abs(a[i].S-a[i-d].S);
  }


  int q;
  cin >> q;
  rep(aaa,q){
    int l,r; cin>>l>>r;
    cout << sum[r]-sum[l] << endl;
  }
  return 0;
}
