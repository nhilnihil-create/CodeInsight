#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  int n,i,p=0,c=0;
  cin>>s;
  n=s.length();
  if(s.at(0)!='A') cout<<"WA"<<endl;
  else{
    for(i=1;i<n;i++){
      if('A'<=s.at(i)&&s.at(i)<='Z'){
        c++;
        if(s.at(i)=='C') p=i+1;
      }
    }
    if(c==1&&3<=p&&p<=n-1) cout<<"AC"<<endl;
    else cout<<"WA"<<endl;
  }
}