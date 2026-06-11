#include<bits/stdc++.h>
#define rep(i,n) for (int i =0; i <(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main(){
  int N, K;
  cin >> N >> K;
  
  double ans = 0;
  
  for(int i = 1; i <= N; i++){
    int score = i;
    double tmp = 1.0 / N; //まずさいころを振ってiが出る確率は1/N
    int count = 0;

    while(score < K){
      score *=2;
      tmp /= 2; //コインで表を出さなければいけない回数ぶんだけ確率が落ちる
    }
    
    ans += tmp;
    

  }
  
  cout << setprecision(12) << ans << endl;
}