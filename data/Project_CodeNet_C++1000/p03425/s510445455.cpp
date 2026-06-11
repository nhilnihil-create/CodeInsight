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
  ll n,cnt[5]={0};
  string s[100010];
  cin>>n;
  rep(i,n)cin>>s[i];

  rep(i,n){
    if(s[i][0]=='M')cnt[0]++;
    if(s[i][0]=='A')cnt[1]++;
    if(s[i][0]=='R')cnt[2]++;
    if(s[i][0]=='C')cnt[3]++;
    if(s[i][0]=='H')cnt[4]++;
  }
  ll ans=cnt[0]*cnt[1]*cnt[2]+cnt[0]*cnt[1]*cnt[3]+cnt[0]*cnt[1]*cnt[4]+cnt[0]*cnt[2]*cnt[3]+cnt[0]*cnt[2]*cnt[4]+
  cnt[0]*cnt[3]*cnt[4]+cnt[1]*cnt[2]*cnt[3]+cnt[1]*cnt[2]*cnt[4]+cnt[1]*cnt[3]*cnt[4]+cnt[2]*cnt[3]*cnt[4];
  cout<<ans<<endl;

  return 0;
}
