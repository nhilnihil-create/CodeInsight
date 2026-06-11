#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  string T;
  cin>>S>>T;
  int a[26];
  for(int i=0;i<26;i++){
      a[i]=-1;
  }

  for(int i=0;i<S.length();i++){
    if(a[S.at(i)-'a']==-1){
      a[S.at(i)-'a']=T.at(i)-'a';
    }
    if(a[S.at(i)-'a']>=0){
      if(T.at(i)-'a'==a[S.at(i)-'a']){
        continue;
      }
      else{
        cout<<"No"<<endl;
        return 0;
      }
    }
    
  }
  map<int,int>mp;
  for(int i=0;i<26;i++){
    if(a[i]!=-1){
      mp[a[i]]++;
      if(mp[a[i]]>=2){
        cout<<"No"<<endl;
        return 0;
      }
    }
  }

  cout<<"Yes"<<endl;
  return 0;
}

   