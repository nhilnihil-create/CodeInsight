#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;

int gcd(int a, int b) { //最大公約数
  if (b==0) return a;
  else return gcd(b, a%b);
}

int lcm(int a, int b) { //最小公倍数
  return a * b / gcd(a, b);
}

ll digit_sum(ll a){
  ll ans=0;
  while(a>0){
    ans+=a%10;
    a/=10;
  }
  return ans;
}


int main()
{
  ll n,a,b;
  ll ans=0;
  cin>>n>>a>>b;
  reps(i,n+1){
    if(digit_sum(i)>=a&&digit_sum(i)<=b)ans+=i;
  }
  cout<<ans<<endl;
  return 0;
}
