#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;

ll gcd(ll a, ll b) { //最大公約数
  if (b==0) return a;
  else return gcd(b, a%b);
}

ll lcm(ll a, ll b) { //最小公倍数
  return a * b / gcd(a, b);
}

ll digit_sum(ll a){ //10進桁和
  ll ans=0;
  while(a>0){
    ans+=a%10;
    a/=10;
  }
  return ans;
}



int main()
{
  ll n,a[2][110],ans=0,m=0;
  cin>>n;
  rep(i,n){
    cin>>a[0][i];
    m+=a[0][i];
  }
  rep(i,n)cin>>a[1][i];


  rep(i,n){
    ll tmp=0;
    rep(j,i+1){
      tmp+=a[0][j];
    }
    for(ll k=i;k<n;k++){
      tmp+=a[1][k];
    }
    ans=max(ans,tmp);
  }


  cout<<max(ans,m)<<endl;
  return 0;
}
