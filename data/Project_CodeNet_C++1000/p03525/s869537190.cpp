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
  int N;
  cin>>N;
  VI D(N);
  rep(i,N) cin>>D[i];
  VI X(13);
  rep(i,N) X[D[i]]++;
  rep(i,13){
    if(X[i]>2){
      cout<<0<<endl;
      return 0;
    }
  }
  VI L,R;
  L.pb(0);
  R.pb(0);
  int F=1;
  rep(i,13){
    if(F){
      if(X[i]==2){
        L.pb(i);
        R.pb(i);
      }else if(X[i]==1){
        L.pb(i);
        F=0;
      }
    }else{
      if(X[i]==2){
        L.pb(i);
        R.pb(i);
      }else if(X[i]==1){
        R.pb(i);
        F=1;
      }
    }
  }
  int ans=24-L[L.size()-1]-R[R.size()-1];
  rep(i,L.size()-1) ans=min(ans,L[i+1]-L[i]);
  rep(i,R.size()-1) ans=min(ans,R[i+1]-R[i]);
  cout<<ans<<endl;
}