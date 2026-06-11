#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int

int main(){
  string S;
  cin>>S;
  rep(i,3){
    if(S[i]=='1')
      S[i]='9';
    else
      S[i]='1';

  }

  cout<<S<<endl;


  return 0;
}
