#include <bits/stdc++.h>
using namespace std;

int main (){
  int n;
  cin >> n;
  vector<long long> luca(n+1,0);
  luca.at(0)=2;
  luca.at(1)=1;
  for(int i=2;i<n+1;i++)
  {
    luca.at(i)=luca.at(i-1)+luca.at(i-2);
  }
  cout << luca.at(n) << endl;
}