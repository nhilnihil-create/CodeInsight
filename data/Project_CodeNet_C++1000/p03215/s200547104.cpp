#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector< vector<int> > VVI;
typedef vector< vector<ll> > VVL;
typedef pair<int,int> PII;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
#define ub upper_bound
#define lb lower_bound

int main(){
  int N,K;
  cin>>N>>K;
  VL A(N);
  rep(i,N) cin>>A[i];
  VL Y;
  rep(i,N){
    ll tmp=0;
    rep(j,N-i){
      tmp+=A[i+j];
      Y.pb(tmp);
    }
  }
  ll ans=0;
  rep(i,40){
    ll X=1ll<<(39-i);
    int cnt=0;
    rep(j,Y.size()){
      if(((ans+X)&Y[j])==(ans+X)) cnt++;
    }
    if(cnt>=K) ans+=X;
  }
  cout<<ans<<endl;
}