#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;

vector<ll>multiple;
void prime(int v){
  multiple[0]=-1;
  multiple[1]=-1;
  for(int i=2; i<=v; i++){
    if(multiple[i]!=0)continue;
    for(int j=i*2; j<=v; j+=i){
     multiple[j]=i;
    }
  }
}

int main(){
  ll n;
  cin >> n;
  multiple.resize(n+1);
  prime(n);
  
  vector<ll>count(n+1);
  
  
  for(int i=2; i<n+1; i++){
    ll x = i;
    ll j = 2;
    while(x>1){
      if(multiple[j]!=0){
        j++;
        continue;
      }
      while(x%j==0){
        x/=j;
        count[j]++;
      }
      j++;
    }
  }
  
  ll c3=0,c5=0,c15=0,c25=0,c75=0;
  for(int i=0; i<n+1; i++){
    if(count[i]>=2 && count[i]<=3)c3++;
    if(count[i]>=4 && count[i]<=13)c5++;
    if(count[i]>=14 && count[i]<=23)c15++;
    if(count[i]>=24 && count[i]<=73)c25++;
    if(count[i]>=74)c75++;
  }
  
  //for(int i=1; i<n+1; i++) cout << count[i] << endl;
  //cout << c3 << " " << c5 << " " << c15 << " " << c25 << " " << c75 << endl;
  
  ll ans=0;
  //3*5*5
  ans+=c3*(c5+c15+c25+c75)*(c5+c15+c25+c75-1)/2;
  ans+=(c5+c15+c25+c75)*(c5+c15+c25+c75-1)*(c5+c15+c25+c75-2)/2;
  //5*15
  ans+=c5*(c15+c25+c75);
  ans+=(c15+c25+c75)*(c15+c25+c75-1);
  //3*25
  ans+=(c3+c5+c15)*(c25+c75);
  ans+=(c25+c75)*(c25+c75-1);
  //75
  ans+=c75;
  
  cout << ans << endl;
  
}
  
  
  
