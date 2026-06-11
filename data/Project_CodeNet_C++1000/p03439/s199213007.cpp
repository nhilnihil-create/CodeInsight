#include <bits/stdc++.h>

using namespace std;
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1LL<<60;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

#include <cstdio>
#include <string>

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int N;

int vec_pos[100100];

int decode(string s){

  if(s == "Vacant"){
    return 0;
  }else if(s == "Male"){
    return 1;
  }else{
    return 2;
  }
}

int get_gen(int pos){

  if(vec_pos[pos] >= 0){
    return vec_pos[pos];
  }

  printf("%d\n", pos);
  fflush(stdout);

  string s;
  cin >> s;

  return vec_pos[pos] = decode(s);

}


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);


  scanf("%d", &N);

  rep(i, N){
    vec_pos[i] = -1;
  }

  int left = 0;
  int right = N-1;

  while(right - left > 1){

    int mid = left + (right - left) / 2;

    int L = get_gen(left);
    int M = get_gen(mid);
    int R = get_gen(right);

    if(L == 0){
      cout << left << endl;
      return 0;
    }
    if(M == 0){
      cout << mid << endl;
      return 0;
    }
    if(R == 0){
      cout << right << endl;
      return 0;
    }

    if((mid-left)%2 == abs(L-M)){
      left = mid;
    }else{
      right = mid;
    }
    
  }

  return 0;
}
