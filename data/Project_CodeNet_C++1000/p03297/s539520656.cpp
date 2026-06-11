#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll GCD(ll a, ll b){
  if( b == 0 ){ return a;}
  else{ return GCD(b,a%b);}
}


int main(){ 
  ll T; cin >> T;
  
  while(T--){ 
    
    ll a,b,c,d; cin >> a >> b >> c >> d;
    
    if( b > d || a < b ){ cout << "No" << endl; continue;}
    else if( b-1 <= c ){ cout << "Yes" << endl; continue;}
    
    ll g = GCD(b,d);
    
    ll k;
    
    if( c < a ){ 
      ll l;
      if( (a-c) % g == 0 ){ l = (a-c)/g; l--;}
      else{ l = (a-c)/g;}
      
      k = -l;
    }
    else if( c == a ){ k = 1;}
    else{
     if( (c-a) % g == 0 ){ k = (c-a)/g; k++; }
     else{ k = (c-a+g-1)/g;}
    }
    
    ll test = a+g*k;
    
    if( test < b ){ cout << "No" << endl;}
    else{ cout << "Yes" << endl;}
    
  }
  
  return 0;
}