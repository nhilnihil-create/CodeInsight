#include <bits/stdc++.h>
using namespace std;

int main(){
  int s;
  cin >> s;
  
  int m = 0;
  vector<int> a;
  a.push_back(s);
  for (int i=1 ; ; i++){
    if (a.at(a.size()-1)%2 == 0)
      a.push_back(a.at(a.size()-1)/2);
    else
      a.push_back(3*a.at(a.size()-1) + 1);
    for (int j=0 ; j<a.size()-1 ; j++){
      if (a.at(a.size()-1) == a.at(j)){
        m = i+1;
        break;
      }
    }
    if (m != 0)
      break;
  }
  
  cout << m << endl;
}