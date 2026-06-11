#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
typedef long long ll;
typedef pair<int, int> p;

int main(){
  string s;
  cin >> s;
  vector<string>ans(9);
  ans[0]=s[0];
  for(int bit=0;bit<(1<<3);bit++){
    //cout<<bit<<endl;
    int sum=s[0]-'0';
    for(int i =0; i<3;i++){
      //cout<<i<<"aaa"<<endl;
      if(bit&(1<<i)){
        sum+=s[i+1]-'0'; 
        ans[2*(i+1)]=s[i+1];
        ans[2*i+1]='+';
      }
      else{
        sum-=s[i+1]-'0';
        ans[2*(i+1)]=s[i+1];
        ans[2*i+1]='-';
      }
    }

    if(sum==7){
      ans[7]='=';
      ans[8]='7';
      break;
    }
    
  }
  rep(i,9)cout<<ans[i];
  }