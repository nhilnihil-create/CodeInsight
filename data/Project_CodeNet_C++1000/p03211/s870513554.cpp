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
  string s;
  cin>>s;
  ll min=1e15;
  rep(i,s.length()-2){
    ll tmp=(s[i]-'0')*100+(s[i+1]-'0')*10+(s[i+2]-'0');
    if(abs(tmp-753)<min)min=abs(tmp-753);
  }

  cout<<min<<endl;
  return 0;
}
