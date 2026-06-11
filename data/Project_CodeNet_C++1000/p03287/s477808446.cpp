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
  ll N,M;
  cin>>N>>M;
  VL A(N);
  rep(i,N) cin>>A[i];
  VL X(N+1);
  rep(i,N) (X[i+1]=X[i]+A[i])%=M;
  sort(all(X));
  ll ans=0;
  ll cnt=1;
  rep(i,N){
    if(X[i+1]!=X[i]){
      ans+=cnt*(cnt-1)/2;
      cnt=1;
    }else{
      cnt++;
    }
  }
  ans+=cnt*(cnt-1)/2;
  cout<<ans<<endl;
}