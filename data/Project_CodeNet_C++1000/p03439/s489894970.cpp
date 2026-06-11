#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;  cin >> n;
  int m = 0, f = 1, table[] = {1, 1};
  string rep;
  cout << "0\n";  cin >> rep;
  if(rep == "Female")  table[0] = f, table[1] = m;
  else if(rep == "Male") table[0] = m, table[1] = f;
  else  return 0;
  
  int s = 0, t = n;
  for(int i=0; i<50; i++){
    int mid = (s + t) / 2;
    cout << mid << endl;
    cin >> rep;
    if(rep == "Female")
      if(table[mid%2] == f)  s = mid + 1;
      else  t = mid;
    else if(rep == "Male")
      if(table[mid%2] == m)  s = mid + 1;
      else  t = mid;
    else
      return 0;
  }
  
  return 0;
}
