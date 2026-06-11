#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int>kazu(n);
  vector<int>kasu(n);
  for(int i=0;i<n;i++){
    cin >> kazu.at(i);
    kasu.at(i)=kazu.at(i);
  }
  sort(kasu.begin(),kasu.end());
  double ty=(kasu.at(n/2)+kasu.at(n/2-1))/double(2);
  for(int i=0;i<n;i++){
    if(kazu.at(i)<ty)
      cout << kasu.at(n/2);
    else
      cout << kasu.at(n/2-1);
    cout << endl;
  }
  return 0;
}