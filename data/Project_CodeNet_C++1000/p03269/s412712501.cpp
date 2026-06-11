#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <iomanip>
#include <climits>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector< vector<int> > VVI;
typedef vector< vector<ll> > VVL;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define pf push_front
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ub upper_bound
#define lb lower_bound

int main(){
  int L;
  cin>>L;
  L--;
  int LL=L;
  VI X(21);
  rep(i,21){
    X[i]=L&1;
    L>>=1;
  }
  int cnt=0;
  rep(i,21) if(X[i]) cnt++;
  int N=0;
  rep(i,21) if(X[i]) N=i+1;
  vector<tuple<int,int,int>> P(0);
  if(N==cnt) N++;
  rep(i,N-1){
    P.pb(mt(i+1,i+2,(1<<i)));
    P.pb(mt(i+1,i+2,0));
  }
  int tmp=(1<<(N-1));
  rep(i,N-1){
    if((1<<(N-2-i))+tmp-1<=LL){
      P.pb(mt(N-1-i,N,tmp));
      tmp+=(1<<(N-2-i));
    }
  }
  cout<<N<<" "<<P.size()<<endl;
  rep(i,P.size()) cout<<get<0>(P[i])<<" "<<get<1>(P[i])<<" "<<get<2>(P[i])<<endl;
}