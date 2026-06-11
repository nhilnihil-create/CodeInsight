#include<bits/stdc++.h>
using namespace std;

int main(){
  vector<int>a(3);
  cin>>a.at(0)>>a.at(1)>>a.at(2);
  sort(a.begin(),a.end());
  
  if(a.at(0)==a.at(1))
    cout << a.at(2) << endl;
  else
    cout << a.at(0) << endl;
}