#include <bits/stdc++.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> llP;

ll mod(ll a, ll b){
  ll ret=a%b;
  if(ret<0) ret+=b;
  return ret;
}

ll modpow(ll a,ll b,ll c){
  ll res=1;
  while(b>0){
    if(b&1) res=mod(res*a,c);
    a=mod(a*a,c);
    b>>=1;
  }
  return res;
}

int GCD(int x,int y){
  if(x<y){
    swap(x,y);
  }
  while(x%y!=0){
    int temp=x;
    x=y;
    y=temp%y;
  }
  return y;
}

int digitsum(int x){
  int sum=0;
  while(x>0){
    sum+=(x%10);
    x/=10;
  }
  return sum;
}

int main() {
  int n,x;
  cin>>n>>x;
  int a[n];
  for(int i=0;i<n;i++) cin>>a[i];
  sort(a,a+n);
  int ans=0;
  for(int i=0;i<n;i++){
    x-=a[i];
    if(i==n-1){
      if(x==0) ans++;
      continue;
    }
    if(x>=0){
      ans++;
      continue;
    }
    else break;
  }
  cout<<ans<<endl;
  return 0;
}
