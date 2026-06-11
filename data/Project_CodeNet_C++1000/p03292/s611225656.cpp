#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
  vector<int> A(3);
  for(int i=0;i<3;i++){
    cin >> A.at(i);
  }
  int m = min(min(A.at(0),A.at(1)),A.at(2));
  int M = max(max(A.at(0),A.at(1)),A.at(2));
  
  cout << M-m << endl;
  
  return 0;
}
