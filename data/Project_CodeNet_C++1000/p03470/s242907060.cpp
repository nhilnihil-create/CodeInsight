#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, answer=1;
  cin>>n; vector<int> mochis(n);
  for(int i=0; i<n; i++){
    cin>>mochis.at(i);
  }
  sort(mochis.begin(), mochis.end());
  for(int i=0; i<n-1; i++){
    if(mochis.at(i)<mochis.at(i+1)){answer++;}
  }
  cout<<answer<<endl;
}