#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string t;
  cin>>t;
  
  int sum=700;
  if(t.at(0)=='o') sum=sum+100;
  if(t.at(1)=='o') sum+=100;
  if(t.at(2)=='o') sum+=100;
  cout<<sum<<endl;

}
