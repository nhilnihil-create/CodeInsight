#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi std::vector<std::vector<int> >
#define vvl std::vector<std::vector<ll> >
#define MODs 1000000007;
typedef long long int ll;
using namespace std;

int main(int argc, char const *argv[]) {
  string S;
  ll ans = 0;
  std::cin >> S;
  ll N = S.size();
  std::vector<int> A(N), B(N), C(N), HTN(N, 0);
  for(int i=0;i<N;i++){
    A[i] = (i==0?0:A[i-1]);
    B[i] = (i==0?0:B[i-1]);
    C[i] = (i==0?0:C[i-1]);
    HTN[i] = (i==0?0:HTN[i-1]);
    switch (S[i]) {
      case 'A': A[i]++;
                break;
      case 'B': B[i]++;
                break;
      case 'C': C[i]++;
                break;
      case '?': HTN[i]++;
    }
  }
  if(HTN[N-1]>=3){
    ll rui = 1;
    for(int i=0;i<HTN[N-1]-3;i++) rui= (rui*3)%1000000007;
    for(int i=0;i<N;i++) if(S[i]=='B') ans = (ans+(((i==0?0:A[i-1])*(((C[N-1]-C[i])*((rui*27)%1000000007))%1000000007))%1000000007))%1000000007;
    for(int i=0;i<N;i++) if(S[i]=='B') ans = (ans+(((i==0?0:A[i-1])*(((HTN[N-1]-HTN[i])*((rui*9)%1000000007))%1000000007))%1000000007))%1000000007;
    for(int i=0;i<N;i++) if(S[i]=='?') ans = (ans+(((i==0?0:A[i-1])*(((C[N-1]-C[i])*((rui*9)%1000000007))%1000000007))%1000000007))%1000000007;
    for(int i=0;i<N;i++) if(S[i]=='?') ans = (ans+(((i==0?0:A[i-1])*(((HTN[N-1]-HTN[i])*((rui*3)%1000000007))%1000000007))%1000000007))%1000000007;
    for(int i=0;i<N;i++) if(S[i]=='B') ans = (ans+(((i==0?0:HTN[i-1])*(((C[N-1]-C[i])*((rui*9)%1000000007))%1000000007))%1000000007))%1000000007;
    for(int i=0;i<N;i++) if(S[i]=='B') ans = (ans+(((i==0?0:HTN[i-1])*(((HTN[N-1]-HTN[i])*((rui*3)%1000000007))%1000000007))%1000000007))%1000000007;
    for(int i=0;i<N;i++) if(S[i]=='?') ans = (ans+(((i==0?0:HTN[i-1])*(((C[N-1]-C[i])*((rui*3)%1000000007))%1000000007))%1000000007))%1000000007;
    for(int i=0;i<N;i++) if(S[i]=='?') ans = (ans+(((i==0?0:HTN[i-1])*(((HTN[N-1]-HTN[i])*((rui*1)%1000000007))%1000000007))%1000000007))%1000000007;
    std::cout << ans << '\n';
  }else if(HTN[N-1]==0){
    for(int i=0;i<N;i++) if(S[i]=='B') ans = (ans+(((i==0?0:A[i-1])*(((C[N-1]-C[i])*((1)%1000000007))%1000000007))%1000000007))%1000000007;
    std::cout << ans << '\n';
  }else if(HTN[N-1]==1){
    for(int i=0;i<N;i++) if(S[i]=='B') ans = (ans+(((i==0?0:A[i-1])*(((C[N-1]-C[i])*((3)%1000000007))%1000000007))%1000000007))%1000000007;
    for(int i=0;i<N;i++) if(S[i]=='B') ans = (ans+(((i==0?0:HTN[i-1])*(((C[N-1]-C[i])*((1)%1000000007))%1000000007))%1000000007))%1000000007;
    for(int i=0;i<N;i++) if(S[i]=='B') ans = (ans+(((i==0?0:A[i-1])*(((HTN[N-1]-HTN[i])*((1)%1000000007))%1000000007))%1000000007))%1000000007;
    for(int i=0;i<N;i++) if(S[i]=='?') ans = (ans+(((i==0?0:A[i-1])*(((C[N-1]-C[i])*((1)%1000000007))%1000000007))%1000000007))%1000000007;
    std::cout << ans << '\n';
  }else{
    for(int i=0;i<N;i++) if(S[i]=='B') ans = (ans+(((i==0?0:A[i-1])*(((C[N-1]-C[i])*((9)%1000000007))%1000000007))%1000000007))%1000000007;
    for(int i=0;i<N;i++) if(S[i]=='B') ans = (ans+(((i==0?0:A[i-1])*(((HTN[N-1]-HTN[i])*((3)%1000000007))%1000000007))%1000000007))%1000000007;
    for(int i=0;i<N;i++) if(S[i]=='?') ans = (ans+(((i==0?0:A[i-1])*(((C[N-1]-C[i])*((3)%1000000007))%1000000007))%1000000007))%1000000007;
    for(int i=0;i<N;i++) if(S[i]=='?') ans = (ans+(((i==0?0:A[i-1])*(((HTN[N-1]-HTN[i])*((1)%1000000007))%1000000007))%1000000007))%1000000007;
    for(int i=0;i<N;i++) if(S[i]=='B') ans = (ans+(((i==0?0:HTN[i-1])*(((C[N-1]-C[i])*((3)%1000000007))%1000000007))%1000000007))%1000000007;
    for(int i=0;i<N;i++) if(S[i]=='B') ans = (ans+(((i==0?0:HTN[i-1])*(((HTN[N-1]-HTN[i])*((1)%1000000007))%1000000007))%1000000007))%1000000007;
    for(int i=0;i<N;i++) if(S[i]=='?') ans = (ans+(((i==0?0:HTN[i-1])*(((C[N-1]-C[i])*((1)%1000000007))%1000000007))%1000000007))%1000000007;
    std::cout << ans << '\n';
  }

  return 0;
}
