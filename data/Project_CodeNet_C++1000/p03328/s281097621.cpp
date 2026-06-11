#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  cin >> a >> b;
  vector<int> sum(1000);
  sum.at(0)=0;
  for(int i=1;i<=999;i++){
    sum.at(i)=sum.at(i-1)+i;
  }
  int diff=b-a;
  cout << sum.at(diff)-b << endl;
  return 0;
}
