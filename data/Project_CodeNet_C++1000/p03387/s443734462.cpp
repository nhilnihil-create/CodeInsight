#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
 

  vector<int> a(3);
  cin>>a.at(0)>>a.at(1)>>a.at(2);

  sort(a.begin(),a.end());

  int wk1 = a.at(2)-a.at(1);
  int wk2 = a.at(2)-(a.at(0)+wk1);
  int wk3 = ceil(wk2/2.0)+wk2%2;

  cout<<wk1+wk3<<endl;


	return 0;
}