#include<bits/stdc++.h>
using namespace std;
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define rep(i,n) for(int i=0; i<(n); ++i)
#define per(i,n) for(int i=n-1;i>=0;++i)
#define rep1(i,n) for(int i=1; i<=n; ++i)
#define per1(i,n) for(int i=n; i>=1; ++i)
#define debug cout << "line : " << __LINE__ << " debug" << endl
#define Dcout(N) cout << setprecision(20) << N << endl
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() ) //被り削除
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define INF 1e9
#define MOD 1000000007
typedef long long ll;
//------------------------------------------------------------------------

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n,a,b; cin >> n >> a >> b;
  int mx = min(a,b);
  if(a+b>n){
    cout << mx << " " << a+b-n << endl;
  }else{
    cout << mx << " " << 0 << endl;
  }


  return 0;
}
