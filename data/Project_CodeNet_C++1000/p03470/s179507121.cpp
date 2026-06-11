#include <bits/stdc++.h>
using namespace std;
int N,i,j,array;
 
int main() {
  cin >>  N;
  set<int> mochi_array;
  
  for(i=0;i<N;i++){
    
  	cin >> j ;
    mochi_array.insert(j);
  }
  cout<<mochi_array.size()<<endl;
  return 0;
}
 
