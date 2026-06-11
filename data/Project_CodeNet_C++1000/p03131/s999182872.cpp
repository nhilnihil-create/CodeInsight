#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int K,A,B;
  cin>>K>>A>>B;
  if(B-A<=2)
    cout<<K+1<<endl;
  else
    cout<<(K-(A-1))/2*(B-A)+A+(K-(A-1))%2<<endl;
}