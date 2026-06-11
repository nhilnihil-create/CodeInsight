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
typedef pair<ll,ll> PLL;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
#define ub upper_bound
#define lb lower_bound

int main(){
  int N;
  cin>>N;
  VI A(N),B(N);
  rep(i,N) cin>>A[i];
  rep(i,N) cin>>B[i];
  ll sum=0;
  rep(i,N) sum+=max(0,B[i]-A[i]);
  if(sum==0){
    cout<<0<<endl;
    return 0;
  }
  VI C;
  rep(i,N) if(A[i]>B[i]) C.pb(A[i]-B[i]);
  sort(all(C),greater<int>());
  ll tmp=0;
  rep(i,C.size()){
    tmp+=C[i];
    if(tmp>=sum){
      cout<<N-C.size()+i+1;
      return 0;
    }
  }
  cout<<-1<<endl;
}