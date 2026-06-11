#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  int k;
  cin>>k;
  
  if(k%2==1) cout<<(k+1)/2*(k/2)<<endl;
  else cout<<k/2*(k/2)<<endl;
  
  return 0;
}