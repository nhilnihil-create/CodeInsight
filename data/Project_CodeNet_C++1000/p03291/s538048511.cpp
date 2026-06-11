#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;

ll a = 0,b = 0,c = 0,ab = 0,abc = 0;

ll p3(ll x){
  // 3^x mod MODを返したい
 
  if( x == 0){ return 1LL;}
  
  if( x%2 == 0){ 
    ll res = p3(x/2);
    res = (res*res)%MOD;
    return res;
  }
  else{
    ll res = p3((x-1)/2)%MOD;
    res = (res*res)%MOD;
    return (res*3)%MOD;
  }
}

int main(){
  
  string S; cin >> S; int n = (int)S.size();
  
  ll q = 0;

  for(int i = 0; i < n; i++){ 
    
    if(S[i] == 'A'){ 
      a = a+p3(q);
      a %= MOD;
    }
    if(S[i] == 'B'){ 
      ab = ab+a;
      b = b+p3(q);
      ab %= MOD;
      b %= MOD;
    }
    if(S[i] == 'C'){
      abc = abc+ab;
      c = c+p3(q);
      abc %= MOD;
      c %= MOD;
    }
    if(S[i] == '?'){ 
      abc = 3*abc+ab;
      ab = 3*ab+a;
      a = 3*a+p3(q);
      b = 3*b+p3(q);
      c = 3*c+p3(q);
      q++;
      
      abc %= MOD;
      ab %= MOD;
      a %= MOD;
      b %= MOD;
      c %= MOD;
      
    }
   
  }
  
  cout << abc << endl;
  
  return 0;
}
    