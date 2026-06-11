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
typedef vector< vector<int> > VVI;
typedef pair<int,int> P;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()

int main(){
  int N;
  cin>>N;
  VI X(100);
  rep(i,N){
    int Y=i+1;
    rep(j,10){
      rep(k,i){
        if(Y%(k+2)==0){
          X[k+1]++;
          Y/=(k+2);
          break;
        }
      }
    }
  }
  sort(all(X));
  int n2=X.end()-lower_bound(all(X),2);
  int n4=X.end()-lower_bound(all(X),4);
  int n14=X.end()-lower_bound(all(X),14);
  int n24=X.end()-lower_bound(all(X),24);
  int n74=X.end()-lower_bound(all(X),74);
  ll ans=0;
  ans+=max(0,n4*(n4-1)/2*(n2-2));
  ans+=max(0,n14*(n4-1));
  ans+=max(0,n24*(n2-1));
  ans+=max(0,n74);
  cout<<ans<<endl;
}