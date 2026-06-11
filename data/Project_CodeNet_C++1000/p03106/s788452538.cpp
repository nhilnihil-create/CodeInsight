#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,k;
  cin >> a >> b >> k;
  
  vector<int> data;
  
  for(int i=1;i<=min(a,b);i++){
    if(a%i==0&&b%i==0){
      data.push_back(i);
    }
  }
  sort(data.begin(),data.end(),std::greater<int>());
  cout << data.at(k-1);
}
