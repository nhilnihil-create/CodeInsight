#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;

int n,a,b,k;  
string s;

int main() {
  cin >> a >> b >> k;
  int c,d;
  rep(i,k){
    if(!(i&1)){
      if(a&1) a--;
      a/=2,b+=a;
    }else{
      if(b&1) b--;
      b/=2,a+=b;
    }
  }
  cout << a << " " << b << endl;
}