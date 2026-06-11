#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int n=0;
  for(int i=0;i<s.size();i++)
    n+=(s.at(i)=='+'?1:-1);
  cout<<n<<endl;
}