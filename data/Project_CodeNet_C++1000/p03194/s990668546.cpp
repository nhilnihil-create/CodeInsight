#include<iostream>
#include<algorithm>
#include<set>
#include<math.h>
#include<vector>
#include<sstream>
#include<queue>
#include<functional>
#include<bitset>
#include<cstdio>
#include<iomanip>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include <string.h>
using ll = long long;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define reps(i,x) for(ll i=1;i<=(ll)(x);i++)
#define rrep(i,x) for(ll i=((ll)(x)-1);i>=0;i--)
#define rreps(i,x) for(ll i=(ll)(x);i>0;i--)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))
#define vll vector<ll>
#define vi vector<int>
#define vpll vector<pair<ll,ll>>
#define vpi vector<pair<int,int>>
#define mod 1000000007 
using namespace std;
int a[1000];
int b[1000];
vector<bool> IsPrime;

void sieve(size_t max){
    if(max+1 > IsPrime.size()){     // resizeで要素数が減らないように
        IsPrime.resize(max+1,true); // IsPrimeに必要な要素数を確保
    } 
    IsPrime[0] = false; // 0は素数ではない
    IsPrime[1] = false; // 1は素数ではない

    for(size_t i=2; i*i<=max; ++i) // 0からsqrt(max)まで調べる
        if(IsPrime[i]) // iが素数ならば
            for(size_t j=2; i*j<=max; ++j) // (max以下の)iの倍数は
                IsPrime[i*j] = false;      // 素数ではない
}
int main() {
  long n,p;
  cin >> n >> p;
  int sq = floor(sqrt(p));
  sieve(sq);
  long q = p;
  vector<long> el;
  if(n == 1){
    cout << p << endl;
    return 0;
  }
  for(long i = 2; i <= sq; i++){ 
    if(IsPrime[i]){
      if(q % i == 0) {
        if(q > 1){
          while(q>1 && (q % i ==0)){
            q /= i;
            el.push_back(i);
          }
        }
      }
    }
    if(i == sq && q > 1)
      el.push_back(q);
  }
  int i = 0;
  long pre = -1;
  vector<int> ans;
  for(auto e: el){
    if(!i){
      pre = e;
      i++;
    }else if(pre == e){
      i++;
      if(i % n == 0)
        ans.push_back(e);
    }else{
      i = 1;
      pre = e;
    }
  }
  long as = 1;
  for(auto e: ans){
    as *= e;
  }
  cout << as << endl;
  
}
