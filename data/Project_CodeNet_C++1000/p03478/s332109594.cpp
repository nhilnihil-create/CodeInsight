#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n,a,b;cin>>n>>a>>b;
      int cnt=0;
  for(int i=1;i<=n;i++){
    int c=i,ans=0;
    while(c){
      ans+=c%10;
      c/=10;
    }
    if(a<=ans&&ans<=b)cnt+=i;
  }
  cout<<cnt<<endl;
}