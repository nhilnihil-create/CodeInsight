#include <bits/stdc++.h>
using namespace std;
 
int main() {
  vector<int> a(4);
  for(int i =0;i<6;i++){
    int m;
    cin >>m;
    a.at(m-1)++;
  }
  int cnt =0;
  for(int i=0;i<4;i++){
    if( a.at(i)==2){
      cnt ++;
    }
  }
  cout << ( cnt ==2 ? "YES":"NO");
      
}
    