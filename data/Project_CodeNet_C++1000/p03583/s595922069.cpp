#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll mod= 1e9 + 7;


int main(){
  ll n;
  cin >> n;
  for(ll a=1;a<3501;a++){
    for(ll b=1;b<3501;b++){
        if(4*a*b-n*(a+b)>0 && n*a*b%(4*a*b-n*(a+b))==0){
          cout << a << " " << b << " " << n*a*b/(4*a*b-n*(a+b)) <<endl;
          return 0;
        }
    }
  }
}