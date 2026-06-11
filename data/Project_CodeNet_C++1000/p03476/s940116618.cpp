#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  vector<int> s(100005,0),a(100005,0);
  vector<bool> isPrime(100005,true);
  int q,l,r;
  cin>>q;
  isPrime[0]=isPrime[1]=false;

  for(int i=2;i*i<=100000;i++) if(isPrime[i]) for(int j=2*i;j<=100000;j+=i) isPrime[j]=false;
  for(int i=0;i<=100000;i++) a[i]=isPrime[i]&&isPrime[(i+1)/2];
  for(int i=0;i<100000;i++) s[i+1]=s[i]+a[i];

  for(int i=0;i<q;i++) {
    cin>>l>>r;
    cout<<s[r+1]-s[l]<<endl;
  }
}
