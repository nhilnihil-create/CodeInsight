#include <bits/stdc++.h>
using namespace std;
 

int main() {

  int64_t n;
  cin>>n;

  vector<int64_t> X(n);
  for(int i=0;i<n;i++){
    cin>>X.at(i);
  }

  vector<int64_t> X_org=X;

  sort(X.begin(),X.end());

  for(int i=0;i<n;i++){
    int wk=X_org.at(i);

    if(wk<=X.at(n/2-1))
      cout<<X.at(n/2)<<endl;
    else
      cout<<X.at(n/2-1)<<endl;
  }

  return 0;
}