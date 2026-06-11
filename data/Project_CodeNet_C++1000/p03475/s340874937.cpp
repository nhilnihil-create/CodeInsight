#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
#define all(x) (x).begin(),(x).end()

int N;
vector<int> C, S, F;

//スタート駅を渡すとN番目の駅までの時間を返す
int func(int start){
  int time = 0;
  for(int i=start; i<N-1; i++){
    if(time <= S[i]) time = S[i];
    else{
      int x = time - S[i], a = x / F[i], b = x % F[i];
      if(b == 0) time = S[i] + F[i] * a;
      else time = S[i] + F[i] * (a + 1);
    }
    time += C[i];
  }
  return time;
}


int main() {
   cin >> N;
   C.resize(N); S.resize(N); F.resize(N);
   for(int i=0; i<N-1; i++){
     cin >> C[i] >> S[i] >> F[i]; 
   }

   for(int i=0; i <N; i++){
     cout << func(i) << ln;
   }
 }
