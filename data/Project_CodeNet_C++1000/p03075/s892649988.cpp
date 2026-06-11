#include <bits/stdc++.h>
using namespace std;

int main() {
  int k;
  vector<int> A(5);
  for(int i=0;i<5;i++){
    cin >> A.at(i);
  }
  cin >> k;
  sort(A.begin(),A.end());
  if(A.at(4)-A.at(0)>k){
    cout << ":(" << endl;
  }
  else{
    cout << "Yay!" << endl;
  }
}