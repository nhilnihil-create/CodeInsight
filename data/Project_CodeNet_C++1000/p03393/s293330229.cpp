#include <bits/stdc++.h>
using namespace std;
//難しい解説ACできず保留
int main() {
  string s;
  cin>>s;
  string t="zyxwvutsrqponmlkjihgfedcba";
  if(s==t){
    cout<<-1<<endl;
    return 0;
  }
  vector<bool> siyou(26,0);
  int n=s.size();
  for(int i=0;i<n;i++){
    int x=s[i]-'a';
    siyou[x]=1;
    //cout<<x<<endl;
  }
  if(s.size()==26){
    string u;
    for(int i=0;i<26;i++){
      if(s[i]=='z'){
        bool hantei=true;
        int irekae;
        for(int j=i+1;j<25;j++){
          if(s[j]< s[j+1]){
            hantei=false;
            irekae=j;
          }
        }
        if(hantei){
          for(int k=i;k<n;k++){
          int x=s[k]-'a';
          siyou[x]=0;
          //cout<<x<<endl;
          }
          u=s.substr(0,i);
          int count=0;
          //cout<<"koko"<<siyou[s[i-1+count]-'a'+1];
          while(siyou[s[i-1+count]-'a'+1]==1){
            count++;
          }
          u[i-1]=(char)(s[i-1]+count+1);
          //cout<<(char)(s[i-1]+count+1)<<" kore "<<i-1;
          cout<<u<<endl;
          return 0;
        }else{
          for(int k=irekae;k<n;k++){
          int x=s[k]-'a';
          siyou[x]=0;
          //cout<<x<<endl;
          }
          u=s.substr(0,irekae+1);
           int count=0;
          //cout<<"koko "<<u[irekae]<<" ";
          while(siyou[u[irekae]+count-'a'+1]==1){
            count++;
            //cout<<"check "<<siyou[u[irekae]+count-'a'+1];
          }
         //cout<<"koko"<<(char)(u[irekae]+count+1);
          u[irekae]=(char)(u[irekae]+count+1);
          cout<<u<<endl;
          return 0;
        }
      }
    }
  }else{
    char c;
    for(int i=0;i<26;i++){
      if(siyou[i]==0){
        c=i+'a';
        break;
      }
    }
    cout<<s<<(char)c<<endl;
    return 0;
  }
  return 0;
}