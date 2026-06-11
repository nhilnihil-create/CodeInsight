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
  ll a,b;
  ll ans=0;
  cin>>a>>b;
  for(ll i=a;i<=b;i++){
    ll a,b,c,d,tmp=i;
    a=tmp%10;
    tmp/=10;
    b=tmp%10;
    tmp/=10;
    c=tmp%10;
    tmp/=10;
    d=tmp%10;
    tmp/=10;
    if(tmp==a&&b==d)ans++;
  }

  cout<<ans<<endl;
  return 0;
}
