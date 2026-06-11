#include <bits/stdc++.h>
using namespace std; 
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a) (a).begin(),(a).end()
#define ll long long
long long min(long long x,long long y){return (x<y ? x:y);}
long long max(long long x,long long y){return (x>y ? x:y);}
#define ld long double
int stoi(string s) {return atoi(s.c_str());}
int keta(ll x){ if(x<10){return 1;} else{return keta(x/10) + 1;}}
#define LINEY "YES\n"
#define Liney "Yes\n"
#define LINEN "NO\n"
#define Linen "No\n"

int main(){
  int a[3]; REP(i,3){cin >>a[i];}
  sort(a,a+3);
  int r;
  if(a[0]<a[1]){r = a[0];}
  else{r = a[2];}
  printf("%d\n",r);
}