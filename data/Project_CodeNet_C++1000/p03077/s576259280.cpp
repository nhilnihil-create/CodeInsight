#include<bits/stdc++.h>
using namespace std;

int main(){
  int64_t n;
  cin >> n;
  vector<int64_t>t(5);
  for(int i=0;i<5;i++)
    cin >> t.at(i);
  sort(t.begin(),t.end());
  cout << n/t.at(0)+(n%t.at(0)==0?4:5) << endl;
  return 0;
}