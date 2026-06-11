#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,x=0;string a,b,c;cin>>n>>a>>b>>c;
  for(int i=0;i<n;i++){
    if(a.at(i)==b.at(i)){
      if(a.at(i)!=c.at(i))x++;
    }
    else if(a.at(i)==c.at(i)||b.at(i)==c.at(i))x++;
    else x+=2;
  }
  cout<<x<<endl;
}