#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  map<char,int> a;
  for(int i=0;i<s.size();i++)
    a[s.at(i)]++;
  cout<<(a['a']==1&&a['b']==1&&a['c']==1?"Yes":"No")<<endl;
}