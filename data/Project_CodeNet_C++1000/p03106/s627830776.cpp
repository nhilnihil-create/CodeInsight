#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e9;
const int mod = 1e9+7;

vector<int> fac(300001); //n!(mod M)
vector<int> ifac(300001); //k!^{M-2} (mod M)

long long fpow(long long a,long long n){
  long long ret=1;
  if(n==1) return a;
  if(n%2==0) {
      ret = fpow(a*a%mod, n/2) %mod ;
  }else {
      ret = (a%mod)*fpow(a*a%mod, n/2) %mod;
  }
  return ret %mod;
}
int comb(int a, int b){ //aCbをmod計算
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    int tmp = ifac[a-b]* ifac[b] % mod;
    return tmp * fac[a] % mod;
}
const int D = 60;
int to[D][MX];


signed main(){
    int a, b, k;
    cin >> a >> b >> k;
    int cnt = 0;
    deque<int> arr;
    FOR(i,1,min(a,b)+1) {
        if(a%i==0&&b%i==0) arr.push_back(i);
    }
    cout << arr[arr.size()-k] << endl;
    return 0;
}