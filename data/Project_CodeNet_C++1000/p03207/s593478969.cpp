#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,mmm=0,sum=0;
  cin >> n;
  vector<int> data(n);
  for(int i=0; i<n; i++){
    cin >> data[i];
    mmm=max(mmm,data[i]);
    sum+=data[i];
  }
  
  cout << sum-(mmm/2) << endl;
}
  
