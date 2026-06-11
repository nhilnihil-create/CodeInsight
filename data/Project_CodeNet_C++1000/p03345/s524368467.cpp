#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,k1,k2;
  int64_t k,ans=0;
  cin >> a >> b >> c >> k;
  for(int i=0;i<k;i++){
    k1=a;
    k2=b;
    a=b+c;
    b=k1+c;
    c=k1+k2;
    if(abs(a-b)>=1000000000000000000){
      cout << "Unfair" << endl;
      return 0;
    }
  }
  ans=a-b;
  cout << ans << endl;
}
