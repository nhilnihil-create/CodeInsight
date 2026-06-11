#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int GCD(int a,int b){
  if(a<b){swap(a,b);}  
  if(a%b==0){return b;}
  else{return GCD(a%b,b);} 
}

int main(){
  int a,b,k;cin>>a>>b>>k;
  int g=GCD(a,b);
  int d=1;
  while (true){
    if(g%d==0){k--;}
    if(k==0){cout<<g/d;break;}
    d++;
  }
  
}