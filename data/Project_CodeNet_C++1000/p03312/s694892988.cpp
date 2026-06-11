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
  int N;
  cin>>N;
  VI A(N);
  rep(i,N) cin>>A[i];
  VL L(N+1),R(N+1);
  rep(i,N) L[i+1]=L[i]+A[i];
  reverse(all(A));
  rep(i,N) R[i+1]=R[i]+A[i];
  ll ans=LLONG_MAX;
  rep(i,N-3){
    int tmp=i+1;
    ll sumL=L[tmp+1];
    ll sumR=R[N-1-tmp];
    ll D,S;
    auto itr=lb(all(L),sumL/2);
    D=max(*itr,sumL-*itr);
    S=min(*itr,sumL-*itr);
    itr--;
    if(abs(*itr-(sumL-*itr))<D-S){
      D=max(*itr,sumL-*itr);
      S=min(*itr,sumL-*itr);
    }
    ll D2,S2;
    itr=lb(all(R),sumR/2);
    D2=max(*itr,sumR-*itr);
    S2=min(*itr,sumR-*itr);
    itr--;
    if(abs(*itr-(sumR-*itr))<D2-S2){
      D2=max(*itr,sumR-*itr);
      S2=min(*itr,sumR-*itr);
    }
    ans=min(ans,max(D,D2)-min(S,S2));
  }
  cout<<ans<<endl;
}
