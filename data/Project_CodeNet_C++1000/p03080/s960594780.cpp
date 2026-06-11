#include<bits/stdc++.h>
#include <math.h>
#include <limits.h>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);++i)
#define reps(i,n) for(int i=1;i<=(n);++i)
#define repr(i,n) for(int i=(n);i>=0;--i)
const long long INF = 1LL<<60;
const long long MOD = 1e9+7;
int gcd(int a,int b){if(b==0)return a;return gcd(b,a%b);}
int lcm(int a,int b){return a/gcd(a,b)*b;}
void Yes(){cout<<"Yes"<<endl;}
void No(){cout<<"No"<<endl;}
void YN(bool b){cout<<(b?"Yes":"No")<<endl;}

int main(void){
  long long int n,k,i,j;

  string s;
  cin >> n >> s;
  
  int r = 0;
  int b = 0;
  for(auto ch: s){
    if(ch=='R'){
      r++;
    }
    else{
      b++;
    }
  }
  
  YN(r>b);
  return 0;
}


