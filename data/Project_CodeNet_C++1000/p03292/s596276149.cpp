#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> A(3);
  for(int &i:A)
    cin>>i;
  sort(A.begin(),A.end());
  cout<<A.at(2)-A.at(0)<<endl;
}