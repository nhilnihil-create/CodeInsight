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
  ll K,A,B;
  cin>>K>>A>>B;
  if(B-A<2||K<A-1){
    cout<<K+1;
    return 0;
  }
  ll ans=A;
  if((K-A+1)%2) ans++;
  ans+=(K-A+1)/2*(B-A);
  cout<<ans<<endl;
}