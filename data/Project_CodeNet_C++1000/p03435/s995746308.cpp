#include <bits/stdc++.h>
using namespace std;
int main(){
 vector<vector<long long>> vec(3, vector<long long>(3));
  for(long long i = 0; i < 3; i++){
    for(long long j = 0; j < 3; j++){
      cin >> vec.at(i).at(j);
    }
  }
vector<long long>y(3);
  for(long long i = 0; i < 3; i++){
    y.at(i) = vec.at(i).at(0) - vec.at(0).at(0); 
  }
  if(vec.at(1).at(1) == y.at(1) + vec.at(0).at(1) && 
     vec.at(1).at(2) == y.at(1) + vec.at(0).at(2) &&
     vec.at(2).at(1) == y.at(2) + vec.at(0).at(1) &&
     vec.at(2).at(2) == y.at(2) + vec.at(0).at(2)){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}
   