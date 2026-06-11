#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;i++){
    cin>>a.at(i);
  }
  vector<int>l(n),r(n);
  for(int i=0;i<(n-1);i++){
    l.at(i+1)=gcd(l.at(i),a.at(i));
  }
    for(int i=n-1;i>=1;i--){
      r.at(i-1)=gcd(r.at(i),a.at(i));
    }
      int ans=1;
  for(int i=0;i<n;i++){
    ans=max(ans,gcd(l.at(i),r.at(i)));
  }
    cout<<ans<<endl;
}

      