#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B;
  cin>>A>>B;
  vector<int> C={A,A-1,B,B-1};
  sort(C.begin(),C.end());
  cout<<C.at(2)+C.at(3)<<endl;
}