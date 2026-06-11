#include <bits/stdc++.h>
using namespace std;
 

int main() {

  int64_t n;
  cin>>n;

  vector<int64_t> A(n);
  for(int i=0;i<n;i++){
    cin>>A.at(i);
  }

  sort(A.begin(),A.end());

  cout<<A.back()-A.front()<<endl;

  return 0;
}