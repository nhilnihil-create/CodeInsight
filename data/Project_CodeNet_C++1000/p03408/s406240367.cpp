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
  ll n,m,ans=0LL;
  map<string,ll> mp;
  string s[110],t[110];

  cin>>n;
  rep(i,n){
    cin>>s[i];
    mp[s[i]]++;
  }
  cin>>m;
  rep(i,m){
    cin>>t[i];
    mp[t[i]]--;
  }

  rep(i,n){
    ans=max(ans,mp[s[i]]);
  }



  cout<<max(ans,0LL)<<endl;
  return 0;
}
