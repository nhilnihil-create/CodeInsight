#include <stdlib.h>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
using ll=long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
inline constexpr ll gcd(ll a,ll b){if(!a||!b)return 0;while(b){ll c=b;b=a%b;a=c;}return a;}
inline constexpr ll lcm(ll a,ll b){if(!a||!b)return 0;return a*b/gcd(a,b);}

int main() {
  int a;
  cin>>a;
  string s,t,u;
  cin>>s>>t>>u;
  int count=0;
  rep(i,a){
    if(s.at(i)==t.at(i)&&t.at(i)==u.at(i)){
    }
    else{
      if(s.at(i)==t.at(i)||s.at(i)==u.at(i)||t.at(i)==u.at(i)){
        count+=1;
      }
      else{
        count+=2;
      }
    }
  }
  cout<<count<<endl;
}
