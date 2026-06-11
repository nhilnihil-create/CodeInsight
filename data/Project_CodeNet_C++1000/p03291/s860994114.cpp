#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long
#define MOD 1000000007

using namespace std;

// x^n in mod
ll modpow(ll x, ll n, ll mod){
  if(n==0) return 1;

  if(n%2==0){
    return modpow(x*x%mod, n/2, mod) % mod;
  }else{
    return x * modpow(x, (n-1), mod) % mod;
  }
}

int main(){
  string s;cin>>s;
  ll a_counter[100000];
  ll c_counter[100000];
  ll a_count=0;
  ll c_count=0;
  a_counter[0]=0;
  if(s[0]=='A')a_counter[0]=1;
  if(s[0]=='?'){a_counter[0]=1;a_count++;}
  c_counter[s.size()-1]=0;
  if(s[s.size()-1]=='C')c_counter[s.size()-1]=1;
  if(s[s.size()-1]=='?'){c_counter[s.size()-1]=1;c_count++;}

  for(int i=1; i<s.size()-1; i++){
    if(s[i]=='A'){
      a_counter[i] = ( a_counter[i-1] + modpow(3, a_count, MOD) )%MOD;
    }else if(s[i]=='?'){
      a_counter[i] = ( a_counter[i-1]*3 + modpow(3, a_count, MOD) )%MOD;
      a_count++;
    }else{
      a_counter[i]=a_counter[i-1];
    }


    if(s[s.size()-1-i]=='C'){
      c_counter[s.size()-1-i] = ( c_counter[s.size()-i] + modpow(3, c_count, MOD) )%MOD;
    }else if(s[s.size()-1-i]=='?'){
      c_counter[s.size()-1-i] = ( c_counter[s.size()-i]*3 + modpow(3, c_count, MOD) )%MOD;
      c_count++;
    }else{
      c_counter[s.size()-1-i] = c_counter[s.size()-i];
    }
  }

  ll result=0;
  for(int i=1; i<s.size()-1; i++){
    if(s[i]=='B' || s[i]=='?'){
//cout<<a_counter[i-1]<<'*'<<c_counter[i+1]<<'='<<a_counter[i-1]*c_counter[i+1]%MOD<<endl;
      result += a_counter[i-1]*c_counter[i+1]%MOD;
    }
  }

  cout<<result%MOD<<endl;

//rep(i,s.size())cout<<a_counter[i]<<' ';cout<<endl;
//rep(i,s.size())cout<<c_counter[i]<<' ';cout<<endl;

  return 0;
}