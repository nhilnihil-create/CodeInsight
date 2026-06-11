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
  int N,Z,W;
  cin>>N>>Z>>W;
  VI A(N);
  rep(i,N) cin>>A[i];
  if(N==1){
    cout<<abs(A[0]-W)<<endl;
    return 0;
  }
  cout<<max(abs(A[N-2]-A[N-1]),abs(A[N-1]-W))<<endl;
}