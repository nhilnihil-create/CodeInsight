#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define rep2(i,n) for(int i=0;i<=n;i++)
#define repr(i,a,n) for(int i=a;i<n;i++)
#define all(a) a.begin(),a.end()
#define P pair<long long,long long>
#define uni(e) e.erase(unique(e.begin(),e.end()),e.end())
#define double long double
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int INF=1e10;
int MOD=1e9+7;
template<class T> void out(T a){cout<<a<<'\n';}
template<class T> void yesno(T b){if(b)out("yes");else out("no");}
template<class T> void YesNo(T b){if(b)out("Yes");else out("No");}
template<class T> void YESNO(T b){if(b)out("YES");else out("NO");}
template<class T> void noyes(T b){if(b)out("no");else out("yes");}
template<class T> void NoYes(T b){if(b)out("No");else out("Yes");}
template<class T> void NOYES(T b){if(b)out("NO");else out("YES");}
int keta(int a){
  double b=a;
  b=log10(b);
  int c=b;
  return c+1;
}
int gcd(int a,int b){
  if(a%b==0)
    return b;
  return gcd(b,a%b);
}
int lcm(int a,int b){
    return a/gcd(a,b)*b;
}
bool sosuu(int a){
  bool b=1;
  if(a<=1)
    return 0;
  else{
  rep1(i,sqrt(a)-1){
  if(a%(i+1)==0)
  b=0;
  }
  return b;
  }
}
signed main(){
  int a,b,c;
  cin>>a>>b>>c;
  YesNo(a==b&&b==c);
    
}
