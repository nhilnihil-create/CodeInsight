#include<bits/stdc++.h>
using namespace std;

int main(){
  int64_t k,a,b,ans=0;
  cin >> k >> a >> b;
  if(b-a>2){
    k-=a-1;
    ans=k/2*(b-a);
    ans+=k%2+a;
  }else{
    ans=k+1;
  }
  cout << ans << endl;
  return 0;
}