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
  VI P(N);
  rep(i,N) cin>>P[i];
  VI Q(N);
  rep(i,N) Q[P[i]-1]=i;
  int ans=0;
  int X=1;
  rep(i,N){
    if(i<N-1){
      if(Q[i+1]>Q[i]) X++;
      else{
        ans=max(ans,X);
        X=1;
      }
    }else ans=max(ans,X);
  }
  cout<<N-ans<<endl;
}



