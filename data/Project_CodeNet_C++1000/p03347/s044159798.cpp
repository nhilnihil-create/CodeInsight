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
  VI A(N);
  rep(i,N) cin>>A[i];
  ll ans=0;
  rep(i,N){
    if(i){
      if(A[i]-A[i-1]>1){
        ans=-1;
        break;
      }else if(A[i]-A[i-1]==1){
        ans++;
      }else ans+=A[i];
    }else{
      if(A[i]){
        ans=-1;
        break;
      }
    }
  }
  cout<<ans<<endl;
}



