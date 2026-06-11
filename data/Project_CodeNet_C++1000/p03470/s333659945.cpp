#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  int cake = 0;
  int dan = 0;
  
  cin >> N ;
  
  vector<int> rice(N);
  for(int i=0;i<N;i++){
    cin>> rice.at(i);
  }
  
  sort(rice.begin(),rice.end());
  
  for(int i=0;i<N;i++){
   if(cake < rice.at(i)){
    cake = rice.at(i);
    dan++;
   }
  }

  cout << dan << endl;
}