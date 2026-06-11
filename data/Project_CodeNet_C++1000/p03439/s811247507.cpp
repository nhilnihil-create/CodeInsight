#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;

const ll MOD=1000000007;

ll abs1(ll a){
  if(a>=0)return a;
  else return -a;
}

ll pow1(ll a,ll b){
  ll p=1;
  for(int i=0;i<b;i++){
    p*=a;
  }
  return p;
}

int digit(ll a,ll b){
  int i=0;
  while(a!=0){
    a/=b;
    i++;
  }
  return i;
}

ll gcd1(ll a,ll b){
  if(a==0 && b==0)return 0;
  ll n;
  while(a%b!=0){
    n=a%b;
    a=b;
    b=n;
  }
  return b;
}

ll solveLinear(ll n,ll m,ll c){
  if(n==0 && m==0)return 0;
  ll a[100],b[100];
  a[0]=n;b[0]=m;
  int i=1;
  while(b[i-1]!=0){
    a[i]=b[i-1];
    b[i]=a[i-1]%b[i-1];
    i++;
  }
  n=i;
  if(c%a[n-1]!=0){
    return 0;
  }
  ll x=c/a[n-1],y=0;
  for(i=1;i<n;i++){
    ll cnt=x;
    x=y;
    y=cnt-(a[n-i-1]/b[n-i-1])*y;
  }
  return x;
}

ll modRev(ll a,ll p){
  ll n=solveLinear(a,p,1);
  n=n%p;
  if(n<0)return n+p;
  return n;
}

int main(){
  int i,j,cnt=0;
  int n;
  cin>>n;
  string s="";
  string lc,rc;
  cout<<0<<endl;
  cin>>rc;
  if(rc=="Vacant")return 0;
  int left=0,right=n;
  cnt=1;j=-1;
  while(1){
    i=(left+right)/2;
    if(i==j)i++;
    cout<<i<<endl;
    j=i;
    cin>>s;
    if(s=="Vacant")return 0;
    if(rc==s){
      if((right+i)%2==1)left=i;
      else right=i;
    }else{
      if((right+i)%2==1){
        right=i;
        rc=s;
      }
      else left=i;
    }
    cnt++;
  }
}
