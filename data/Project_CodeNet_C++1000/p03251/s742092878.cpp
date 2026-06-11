#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int n,m,i,t,xmax,ymin;cin >> n >> m >> xmax >> ymin;
  for(i=0;i<n;i++){
    cin >> t;
    xmax = max(xmax,t);
  }
  for(i=0;i<m;i++){
    cin >> t;
    ymin = min(ymin,t);
  }
  cout << ((xmax<ymin) ? "No War":"War") << endl;
}