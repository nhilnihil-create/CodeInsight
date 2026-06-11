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
  int K;
  cin>>K;
  VL X;
  rep(i,999){
    ll tmp=i+1;
    X.pb(tmp);
    rep(j,12){
      tmp=tmp*10+9;
      X.pb(tmp);
    }
  }
  sort(all(X));
  VL S;
  S.pb(X[X.size()-1]);
  double M=(double)X[X.size()-1]/(double)135;
  rep(i,X.size()-1){
    if(X[X.size()-2-i]==X[X.size()-1-i]) continue;
    ll tmp=X[X.size()-2-i];
    int sum=0;
    while(tmp>0){
      sum+=tmp%10;
      tmp/=10;
    }
    if((double)X[X.size()-2-i]/(double)sum<=M){
      S.pb(X[X.size()-2-i]);
      M=(double)X[X.size()-2-i]/sum;
    }
  }
  sort(all(S));
  rep(i,K) cout<<S[i]<<endl;
}