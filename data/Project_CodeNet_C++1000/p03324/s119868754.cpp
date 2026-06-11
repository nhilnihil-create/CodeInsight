#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  int d,n;
  cin>>d>>n;
  
  if(d==0 && n<100) cout<<n<<endl;
  else if(d==0 && n==100) cout<<101;
  else if(d==1 && n<100) cout<<100*n<<endl;
  else if(d==1 && n==100) cout<<10100<<endl;
  else if(d==2 && n<100) cout<<10000*n<<endl;
  else cout<<1010000<<endl;
  return 0; 
}