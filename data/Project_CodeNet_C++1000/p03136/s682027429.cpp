#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++) 

using namespace std;

int main() {
  int n;cin>>n;
  vector<int>l(n);
  int cnt=0;
  rep(i,n)   cin>>l[i];
  sort(l.begin(),l.end());
  rep(i,n-1){
    cnt+=l[i];
  }
  if(l[n-1]<cnt)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}