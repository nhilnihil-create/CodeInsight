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
#define P 1000000007
#define N_MAX 100003
typedef long long int ll;
using namespace std;
ll inv[N_MAX+1];
ll cinv[N_MAX+1];
ll fact[N_MAX+1];
ll finv[N_MAX+1];

void init(){
    cinv[0] = fact[0] = inv[0] = fact[1] = cinv[1] = inv[1] = 1;
    finv[0] = finv[1] = 1;
    for(int i = 2; i <= N_MAX; i++){
      fact[i] = (fact[i-1]*i)%P;
      inv[i] = ((-(P/i)*inv[P%i])%P+P)%P;
      cinv[i] = ((cinv[i-1]*i)%P + fact[i-1])%P;
      finv[i] = (finv[i-1]*inv[i])%P;
    }
}

int main(int argc, char const *argv[]) {
  init();
  ll N, ans=0;
  std::cin >> N;
  std::vector<ll> A(N);
  range(i, N) std::cin >> A[i];
  ll l, r;
  range(i, N){
    l = (cinv[i+1]*finv[i+1])%P;
    r = (cinv[N-i]*finv[N-i])%P;
    ans =  (ans+(A[i]*((l + r)%P + 1000000006)%P)%P)%P;
    //std::cout << ((((l + r)%P + 1000000006)%P)*fact[N])%P << '\n';
  }
  ans = (ans*fact[N])%P;
  std::cout << ans << '\n';
  return 0;
}
