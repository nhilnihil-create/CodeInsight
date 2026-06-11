#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll k,a,b;
  cin>> k >> a >> b;
  ll ans=a;
  if(b-a<=2){
    cout << k+1;
    return 0;
  }
  k=k-(a-1);
  if(k%2==0){
    ans+=(k/2)*(b-a);
  }else{
    ans+=(k/2)*(b-a)+1;
  }
  cout << ans;
}