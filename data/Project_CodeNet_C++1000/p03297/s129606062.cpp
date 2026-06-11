#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repe(i,n) rep(i,(n)+1)
#define per(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pere(i,n) rep(i,(n)+1)
#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000

typedef long long LL;
typedef long double LD;

LL gcd(LL a,LL b){
  if(b%a==0) return a;
  LL tmp;
  while(a%b){
    tmp=a%b;
    a=b;
    b=tmp;
  }
  return b;
}

int main(){
  int t;
  cin >> t;
  for(int q=0;q<t;q++){
    LL a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a<b||d<b){
      cout << "No" << endl;
      continue;
    }
    LL g=gcd(b,d);
    if(a>c) a=a-(a-c+b-1)/b*b;
    a=a+(c-a+g)/g*g;
    if(a<b) cout << "No" << endl;
    else cout << "Yes" << endl;
  }
  return 0;
}