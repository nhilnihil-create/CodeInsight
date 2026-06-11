#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <numeric>
#include <cmath>
#include <cctype>

using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(int i=n; i>-1; --i)
#define ALL(a) (a).begin(),(a).end()
#define FILL(a,x); REP(i,sizeof(a)){ (a)[i]=(x); }
#define CINA(a,n); REP(i,(n)){ cin >> (a)[i]; }
#define FILL2(a,n,m,x); REP(i,(n)){ REP(j,(m)){(a)[i][j]=(x);} }
#define CINA2(a,n,m); REP(i,(n)){ REP(j,(m)){cin >> (a)[i][j];} }
#define Liny "Yes\n"
#define Linn "No\n"
#define LINY "YES\n"
#define LINN "NO\n"

#define umap unordered_map
//cout << setfill('0') << right << setw(4) << 12; // "0012"
int keta(ll x){ if(x<10){return 1;} else{return keta(x/10) + 1;}}
int keta_wa(ll x){ if(x<10){return x;} else{return keta_wa(x/10) + x%10;} }
int ctoi(char c){ return ( (c>='0' && c<='9')? c - '0': 0 );}
int __stoi(string s){ return atoi(s.c_str()); }
ll sum(ll a[],ll N){ return accumulate(a,a+N,0LL);}
ll gcd(ll a,ll b){if(a<b)swap(a,b); return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){if(a<b){swap(a,b);} return a/gcd(a,b)*b;}

ll inf = pow(10,9)+7;

int main(){
  string s; cin>>s;
  ll N = s.size();
  ll dp[N+1][4];
  REPR(i,N){
    REPR(j,3){
      if(i==N){
        if(j==3){ dp[i][j] = 1; }
        else{ dp[i][j] = 0; }
      }else{
        if(j==3){
          int m = ( s[i]=='?'? 3:1);
          dp[i][j] = m * dp[i+1][j];
          dp[i][j] %= inf;
        }else{
          int m1= (s[i]=='?'?3:1);
          int m2;
          if(s[i]=='?'){ m2 = 1; }
          else{
            if((int)(s[i]-'A')==j){ m2 = 1;}
            else{ m2 = 0;}
          }
          dp[i][j] = m1*dp[i+1][j] + m2*dp[i+1][j+1];
          dp[i][j] %= inf;
        }
      }
    }
  }
  cout << dp[0][0] << "\n";
  
}