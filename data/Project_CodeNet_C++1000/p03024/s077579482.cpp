#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int N=s.size();
  int a=15-N;
  for(int i=0;i<N;i++)
    if(s.at(i)=='o')a++;
  if(8<=a)
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;
  return 0;
}