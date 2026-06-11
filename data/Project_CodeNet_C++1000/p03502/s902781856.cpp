#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++) 

using namespace std;

int main() {
  int n;
  cin>>n;
  string s=to_string(n);
  int a=s.size();
  int cnt=0,t=n;
  rep(i,a){
   cnt+=t%10;
    t/=10;
  }
  if(n%cnt==0)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}