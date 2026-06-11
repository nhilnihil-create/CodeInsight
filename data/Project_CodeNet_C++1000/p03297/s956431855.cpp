#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#define range(i, r) for(int i=0;i<r;i++)
#define ranges(i, l, r) for(int i=l;i<r;i++)
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi std::vector<std::vector<int> >
#define vvl std::vector<std::vector<ll> >
#define MODs 1000000007;
#define MODn 1000000009;
typedef long long int ll;
using namespace std;

ll gcd(ll a, ll b){
  if(b > a) swap(a, b);
  ll r = -1;
  while(r!=0){
    r = a % b;
    a = b, b = r;
  }
  return a;
}
int main(int argc, char const *argv[]) {
  int T;
  std::cin >> T;
  ll A, B, C, D, g;
  range(i, T){
    std::cin >> A >> B >> C >> D;
    if(A < B || D < B){
      std::cout << "No" << '\n';
      continue;
    }else if(C >= B){
      std::cout << "Yes" << '\n';
      continue;
    }
    g = gcd(B, D);
    if(g==1){
      std::cout << (B - C>=2?"No":"Yes") << '\n';
      continue;
    }


    if(A % g > C % g){
      C += A % g - C % g;
    }else if(A % g == C % g){
      C += g;
    }else{
      C += (g - C%g + A%g);
    }

    std::cout << (B>C?"No":"Yes") << '\n';
  }
  return 0;
}
