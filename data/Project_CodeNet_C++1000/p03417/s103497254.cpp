#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  long a,b;
  cin >> a>>b;
  long ans;
  if(a==1||b==1){
    ans=max(1LL,a-2LL)*max(1LL,b-2LL);
  }
  else{
    ans=max(0LL,a-2LL)*max(0LL,b-2LL);
  }
 
  cout<<ans<<endl;
 
}