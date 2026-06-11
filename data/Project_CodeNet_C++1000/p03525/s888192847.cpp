#include <iostream>//bit DP
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PP;
int T[55]={0};
int D[55]={0};
int main(){
  int n;cin>>n;
  for(int i=0;i<n;i++){
    cin>>D[i];
  }
  sort(D,D+n);
  T[0]=12;
  for(int i=0;i<n;i++){
    if(i%2==0)T[i+1]=12+D[i];
    else T[i+1]=12-D[i];
  }
  sort(T,T+n+1);
  int mi=min((24-T[n])+T[0],12);
  for(int i=1;i<=n;i++)mi=min(mi,abs(T[i]-T[i-1]));

cout<<mi<<endl;

}
