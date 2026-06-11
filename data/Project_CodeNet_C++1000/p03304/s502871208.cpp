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
  double N,M,D;
  cin>>N>>M>>D;
  double ans=1;
  double X=max(0.0,N-D*2);
  cout<<setprecision(10);
  if(D==0) cout<<X*(M-1)/(N*N)<<endl;
  else cout<<(2*X+N-X)*(M-1)/(N*N)<<endl;
}