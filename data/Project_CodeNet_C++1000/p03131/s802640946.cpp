#include<bits/stdc++.h>
using namespace std;

int main(){
  int64_t k,a,b,ans=1;
  cin >> k >> a >> b;
  if(b-a>2&&k>a-1){
    ans=a;
    k-=a-1;
    ans+=k/2*(b-a);
    //cout << k/2*(b-a) << "#" << k << "#";
    ans+=k%2;
  }else{
    ans+=k;
  }
  cout << ans << endl;
  return 0;
}