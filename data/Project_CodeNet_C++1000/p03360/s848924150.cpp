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
  ll a,b,c,k;
  cin>>a>>b>>c>>k;

  rep(i,k){
    if(max(max(a,b),c)==a)a*=2;
    if(max(max(a,b),c)==b)b*=2;
    if(max(max(a,b),c)==c)c*=2;
  }

  cout<<a+b+c<<endl;
  return 0;
}
