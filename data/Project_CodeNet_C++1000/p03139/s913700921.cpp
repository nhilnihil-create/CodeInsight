#include <stdlib.h>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
using ll=long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
inline constexpr ll gcd(ll a,ll b){if(!a||!b)return 0;while(b){ll c=b;b=a%b;a=c;}return a;}
inline constexpr ll lcm(ll a,ll b){if(!a||!b)return 0;return a*b/gcd(a,b);}
int main() {
   long long a,b,c;
   cin>>a>>b>>c;
   long long d;
   if(a>=c+b){
      d=0;
   }
   else{
      d=c+b-a;
   }
   cout<<min(b,c)<<" "<<d<<endl;
}

