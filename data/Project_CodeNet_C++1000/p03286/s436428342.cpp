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
  int n;
  cin>>n;
  if(n==0){
    cout<<0<<endl;
    return 0;
  }
  vector<int> memo;
  int cnt=0;
  while(n!=0){
    if(n%2==0){
      memo.push_back(0);
      n/=2;
    }
    else{
      memo.push_back(1);
      if(cnt%2==0){
        n--;
        n/=2;
      }
      else{
        n++;
        n/=2;
      }
    }
    cnt++;
  }
  for(int i=(int)memo.size()-1;i>=0;i--){
    cout<<memo[i];
  }
  cout<<endl;
  return 0;
}