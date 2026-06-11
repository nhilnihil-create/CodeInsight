#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main(){
  string S;
  cin>>S;
  vector<int> s(S.length());
  int ans=1000;
  rep(i,S.length()-2){
    int a=S[i]-'0';
    int b=S[i+1]-'0';
    int c=S[i+2]-'0';
    int x=100*a+b*10+c;
    ans=min(ans,abs(753-x));
  }
  cout<<ans<<endl;
}