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
  ll k,one_len=0;
  cin>>s>>k;
  ll tmp=0;
  if(s[tmp]=='1')one_len++;
  while(tmp<s.length()-1){
    if(s[tmp]=='1'&&s[tmp+1]=='1'){
      one_len++;
      tmp++;
    }else{
      break;
    }
  }

  if(one_len>=k){
    cout<<1<<endl;
  }else{
    cout<<s[one_len]<<endl;
  }
  return 0;
}
