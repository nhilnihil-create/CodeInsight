#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int a,b,c;
  vector<int> d(3);
  rep(i,3){
    cin>>d[i];
  }
  sort(d.begin(),d.end());
  a=d[0];b=d[1];c=d[2];
  int ans=0;
  while(a<c-1){
    a+=2;
    ans++;
  }
  while(b<c-1){
    b+=2;
    ans++;
  }
  if(a==c&&b==c){}
  else if(a!=c&&b!=c){
    ans++;
  }else{
    ans+=2;
  }
  cout<<ans<<endl;
}