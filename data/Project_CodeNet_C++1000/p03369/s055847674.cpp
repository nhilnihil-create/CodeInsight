#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  cout<<700+100*((s.at(0)=='o'?1:0)+(s.at(1)=='o'?1:0)+(s.at(2)=='o'?1:0))<<endl;
}