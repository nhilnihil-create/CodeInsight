#include<bits/stdc++.h>
using namespace std;
int main(){
string s,t;
  cin>>s>>t;
  map<char,char>M;
  int N=s.size();
  bool x=true;
  for(int i=0;i<N;i++){
  if(!M.count(s.at(i)))
     M[s.at(i)]=t.at(i);
     else{
     if(t.at(i)!=M.at(s.at(i))){
      x=false; break;
     }
     }
  
  }if(!x)
     cout<<"No"<<endl;
     else{
     set<char>S;
       for(auto p:M){
       auto k=p.first;
         auto v=p.second;
         S.insert(v);
       }
       int m=M.size();
       int n=S.size();
       if(m==n)
         cout<<"Yes"<<endl;
       else
         cout<<"No"<<endl;
           }
   return 0;
}