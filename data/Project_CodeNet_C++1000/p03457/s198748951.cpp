#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  vector<int> t(n+1),x(n+1),y(n+1);
  t.at(0) = 0, x.at(0) = 0, y.at(0) = 0;
  for(int i=1;i<n+1;i++){
    cin >> t.at(i) >> x.at(i) >> y.at(i);
  }
  bool ans = 1;
  for(int i=0;i<n;i++){
    int ta,xa,ya;
    ta = t.at(i+1)-t.at(i);
    xa = max(x.at(i+1)-x.at(i),x.at(i)-x.at(i+1));
    ya = max(y.at(i+1)-y.at(i),y.at(i)-y.at(i+1));
    if(ta >= xa+ya && (ta-xa-ya)%2 == 0){
      continue;
    }
    else{
      ans = 0;
      break;
    }
  }
  if(ans)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}