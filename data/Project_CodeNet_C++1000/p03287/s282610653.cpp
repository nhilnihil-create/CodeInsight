#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n,m,ans=0,t=0;
  cin>>n>>m;
  long long a[n+1];
  a[0]=0;
  for(int i=1;i<n+1;i++){
    long long k;
    cin>>k;
    a[i]=(a[i-1]+k)%m;
    if(a[i]==0)ans++;
  }
  sort(a,a+n+1);
  for(int i=1;i<n;i++){
    if(a[i]==a[i+1])t++;
    else {
      ans+=1LL*t*(t+1)/2;
      t=0;
    }
  }
    cout<<ans+1LL*t*(t+1)/2<<endl;
}
