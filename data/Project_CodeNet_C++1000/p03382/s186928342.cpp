#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll mod= 1e9 + 7;


int main(){
  int n;
  cin >>n;
  int a[n];
  rep(i,n)cin >>a[i];
  sort(a,a+n);
  int g=a[n-1]&2;
  int b,c;
  if(!g){b=c=a[n-1]/2;}else{b=a[n-1]/2;c=b+1;}
  int ans=1000000001;
  int d=0;
  rep(i,n-1){
    if(ans>abs(a[i]-b)){ans=abs(a[i]-b); d=a[i];}
    if(ans>abs(a[i]-c)){ans=abs(a[i]-c); d=a[i];}
  }
  cout << a[n-1] << " " << d << endl; 
} 