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
  int N;
  cin>>N;
  VI A(N),B(N);
  rep(i,N) cin>>A[i]>>B[i];
  ll ans=0;
  VL X(N);
  rep(i,N) X[i]=A[i]+B[i];
  sort(all(X));
  rep(i,(N+1)/2) ans+=X[N-1-i*2];
  rep(i,N) ans-=B[i];
  cout<<ans<<endl;
}