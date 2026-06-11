#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
  string S;
  cin>>S;
  int len=S.size();
  int cnt=0,MAX=0;
  
  rep(i,len){
      if(S[i]=='A'||S[i]=='C'||S[i]=='G'||S[i]=='T'){
          cnt++;
          MAX=max(MAX,cnt);
      }
      else{
          cnt=0;
      }
  }
  cout<<MAX<<endl;
}