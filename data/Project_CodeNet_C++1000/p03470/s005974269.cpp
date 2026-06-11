#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a;
  a =1;
  cin>>n;
  
  vector<int>vect(n);
  for(int i = 0; i<n; i++){
    cin>> vect.at(i);
  }
  
  sort(vect.begin(), vect.end());  
  
  for(int i = 1; i<n; i ++){
    if(vect.at(i-1) < vect.at(i)){
      a ++;
    }
  }
  cout<< a << endl;

}
