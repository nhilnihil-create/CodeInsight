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
  int N;
  cin>>N;
  VI A(N),B(N);
  rep(i,N) cin>>A[i]>>B[i];
  ll sum=0;
  rep(i,N) sum+=A[i];
  int tmp=1001001001;
  rep(i,N){
    if(A[i]>B[i]) tmp=min(tmp,B[i]);
  }
  int F=1;
  rep(i,N) F*=(A[i]==B[i]);
  cout<<(F?0:sum-tmp)<<endl;
}