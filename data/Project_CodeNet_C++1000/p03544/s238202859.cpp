#include<bits/stdc++.h>
using namespace std;
int main(){
  int k;
  cin >> k;
  vector<long long> A(87);
  A.at(0) = 2;
  A.at(1) = 1;
  for(int i=2;i<87;i++){
    A.at(i) = A.at(i-1) + A.at(i-2);
  }
  cout << A.at(k) << endl;
}
