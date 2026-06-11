#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int n;
  cin >> n;
  int tt=0;
  int xx=0;
  int yy=0;
  int i;
  vector<int> t(n);
  vector<int> x(n);
  vector<int> y(n);
  for(i=0;i<n;i++) cin >> t[i] >> x[i] >> y[i];
  for(i=0;i<n;i++){
    if(((t[i]-tt)-(abs(x[i]-xx)+abs(y[i]-yy)))>=0 && (((t[i]-tt)-(abs(x[i]-xx)+abs(\
y[i]-yy)))%2)==0){
      tt = t[i];
      xx = x[i];
      yy = y[i];
    }
    else{
      cout << "No" << "\n";
      return 0;
    }
  }
  cout << "Yes" << "\n";
  return 0;
}