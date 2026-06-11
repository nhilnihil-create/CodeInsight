#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define int ll
#define all(a) a.begin(),a.end()
#define F first
#define S second
#define pb push_back
#define ll long long
#define vi vector<int>
#define pi pair<int,int>
#define mp make_pair

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

const int mod=1e9+7;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int mul(int a,int b)
{
  return ((a)*1ll*(b))%mod;
}

void add_self(int &a,int b)
{
  a+=b;
  if(a>=mod)a-=mod;
}

int add(int a,int b){
  int c=a+b;
  if(c>=mod){
    c-=mod;
  }
  return c;
}

int sub(int a,int b){
  a-=b;
  if(a<0){
    a+=mod;
  }
  return a;
}

int powz(int a,int b)
{
  int res=1;
  while(b)
  {
    if(b&1){
      res=mul(res,a);
    }
    b/=2;
    a=mul(a,a);
  }
  return res;
}

template <typename A, typename B>
istream& operator>>(istream& input,pair<A,B>& x) {
  input>>x.F>>x.S;
  return input;
}

template <typename A>
istream& operator>>(istream& input,vector<A>& x) {
  for(auto& i:x)
    input>>i;
  return input;
}

template<typename A>
ostream& operator<<(ostream& output,vector<A>& x) {
  for(auto& i:x)
    output<<i<<' ';
  return output;
}

const int N=1000002;

ll dp[205][205][205];

void solve(){
  int n;
  cin>>n;
  vi a(n);
  cin>>a;
  reverse(all(a));
  int l=2,r=3;
  if(a[0]>2){
    cout<<-1;
    return;
  }
  for(int i=1;i<n;i++){
    if(l%a[i]){
      l+=(a[i]-l%a[i]);
    }
    r=(r/a[i])*a[i]+a[i]-1;
  }
  int flag=l,flag2=r;
  for(int i=n-1;i>=0;i--){
    flag-=flag%a[i];
    flag2-=flag2%a[i];
  }
  if(flag==2&&flag2==2){
    cout<<l<<' '<<r;
  }
  else{
    cout<<-1;
  }
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc=1;
  //~ cin>>tc;
  for(int _=0;_<tc;_++){
    //~ cout<<"Case #"<<_+1<<": ";
    solve();
    if(_!=tc-1)
      cout<<"\n";
  }
}