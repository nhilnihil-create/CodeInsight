#include <bits/stdc++.h>
using namespace std;

int main(){
  long long a,b,k;
  cin>>k>>a>>b;
  long long ans;
  if(k<a)
    ans=k+1;
  else{
    if(a+2>=b)
      ans=k+1;
    else{
      k -= (a-1);
      ans=(k/2)*b-(k/2-1)*a+k%2;
    }
  }
  cout<<ans<<endl;
}