#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
int main(){
  ll n;
  cin>>n;
  bitset<40> b(0);
  if(!n){
     cout<<0;
     return 0; 
  }
  ll x,cnt,sum,f=0;
  while(n){
     if(n>0){
        sum=x=1;
        cnt=0;
        while(n>sum){
           cnt+=2;
           sum+=x*=4; 
        }
     }else{
        sum=x=-2;
        cnt=1;
        while(n<sum){
           cnt+=2;
           sum+=x*=4; 
        }
     }
     n-=x;
     b.set(cnt);
  }
  string s=b.to_string();
  rep(i,s.size())
     if(f || (f=(s[i]=='1')))
       cout<<s[i]; 
  return 0;
}