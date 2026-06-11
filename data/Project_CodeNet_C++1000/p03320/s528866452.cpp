#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll max_v=1e15;
string ll_to_str(ll n){
  ll digit=0,ten=1;
  while(n/ten>0){
    digit++;
    ten*=10;
  }
  ten/=10;
  string ret;
  while(ten>0){
    ll now_digit=n/ten;
    ret.push_back((char)(now_digit+'0'));
    n-=now_digit*ten;
    ten/=10;
  }
  return ret;
}
ll str_to_ll(string s){
  ll ret=0;
  ll kt=1;
  for(int i=s.length()-1;i>=0;i--){
    ret+=(ll)(s[i]-'0')*kt;
    kt*=10;
  }
  return ret;
}
ll func(ll n){
  string s="0";
  s+=ll_to_str(n);
  bool f=true;
  for(int i=1;i<s.length();i++){
    if(s[i]!='9') f=false;
  }
  if(f) return n;
  ll now_ans=n,now_digit=0;
  for(int i=0;i<s.length();i++) now_digit+=(ll)(s[i]-'0');
  for(int i=s.length()-1;i>=0;i--){
    if(s[i]!='9'){
      int p_d=(int)(s[i]-'0');
      string ks=s;
      for(int j=i+1;j<ks.length();j++) ks[j]='9';
  //    cout<<n<<" "<<i<<" "<<ks<<endl;
      for(int hk=p_d;hk<=9;hk++){
        ks[i]=(int)(hk+'0');
        ll k_num=str_to_ll(ks);
        ll k_digit=0;
        for(int j=0;j<ks.length();j++) k_digit+=(ll)(ks[j]-'0');
        if(k_num==n) continue;
      //  cout<<now_ans<<" "<<now_digit<<" "<<k_num<<" "<<k_digit<<" "<<ks<<endl;
        if(now_ans*k_digit-k_num*now_digit>0){
          now_ans=k_num;
          now_digit=k_digit;
        }
        else if(now_ans*k_digit-k_num*now_digit==0&&now_ans>k_num){
          now_ans=k_num;
          now_digit=k_digit;
        }
      }
    }
  }
  return now_ans;
}
int main(){
  ll k;
  cin>>k;
  ll ans=1;
  for(int i=0;i<k;i++){
    cout<<ans<<endl;
    ans=func(ans+1);
  }
}
