#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n,k;
  cin>>n>>k;
  long long a=0;
  long long b=0;
  for(long long i=1;i<=n;i++){
    if(i%k==0) a++;
    if(i%k==k/2) b++;
  }
  long long ans=a*a*a;
  if(k%2==0) ans+=b*b*b;
  cout<<ans<<endl;
}