#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

ll gcd(ll a, ll b){
  if(a%b) return gcd(b, a%b);
  else return b;
}


int main(){
  int T; cin >> T;
  rep(i, T){
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    if(A<B){
      cout << "No" << endl; continue;
    }
    if(D<B){
      cout << "No" << endl; continue;
    }
    if(C>B){
      cout << "Yes" << endl; continue;
    }
    ll G = gcd(B, D);
    ll ma = A%G + ((B - A%G)/G)*G;
    if(ma>=B) ma-=G;
    if(ma>C){
      cout << "No" << endl;
    }
    else cout << "Yes" << endl;
  }
}