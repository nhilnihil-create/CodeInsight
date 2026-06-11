#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> p(10);
   int sum=0;
  for(int i=0;i<n;i++){
    cin >> p.at(i);
    sum=sum+p.at(i);
  }
  sort(p.begin(),p.end(),greater<>());
  sum=sum-p.at(0)/2;
  cout << sum << endl;

}
