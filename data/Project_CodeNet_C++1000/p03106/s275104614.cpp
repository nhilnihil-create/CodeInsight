#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  int tmp=min(a,b);
 vector<int>res;

  for(int i=1;i<=tmp;i++){
    if(a%i==0&&b%i==0)res.push_back(i);
  }
  reverse(res.begin(),res.end());
  cout<<res[c-1]<<endl;
}