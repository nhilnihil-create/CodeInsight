#include<bits/stdc++.h>
using namespace std;
int main(){
string s;
  cin>>s;
  int N=s.size();
   s+='B';
  string t="";
  for(int i=0;i<N;i++){
  if(s.at(i)!='B')
    t+=s.at(i);
    else{
     if(s.at(i+1)=='C')
       t+='X';
      else{
       t+='B';
        t+=s.at(i+1);
      }
        i++;
    }
  };int64_t ans=0;
  int64_t sum=0;
  reverse(t.begin(),t.end());
  int M=t.size();
  for(int i=0;i<M;i++){
  if(t.at(i)=='X')
    sum++;
    else if(t.at(i)=='A')
      ans+=sum;
    else
      sum=0;
  
  }cout<<ans<<endl;
  
  
    return 0;
}