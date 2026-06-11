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
typedef vector< vector<int> > VVI;
typedef vector< vector<int> > VVL;
typedef pair<int,int> PII;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair

int main(){
  int N,M;
  cin>>N>>M;
  VL X(N),Y(N),Z(N);
  rep(i,N) cin>>X[i]>>Y[i]>>Z[i];
  ll ans=0;
  rep(i,8){
    VL A(N);
    rep(j,N) A[j]=X[j]*pow(-1,(i&1))+Y[j]*pow(-1,(i&2)/2)+Z[j]*pow(-1,(i&4)/4);
    sort(all(A));
    ll sum=0;
    rep(j,M) sum+=A[N-1-j];
    ans=max(ans,sum);
  }
  cout<<ans<<endl;
}