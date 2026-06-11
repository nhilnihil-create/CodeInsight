#include <bits/stdc++.h>
using namespace std;

int main(){
  constexpr int Nbit= 10;
  constexpr int Npat= Nbit+ 1;
  int N;
  cin >> N;

  vector<bitset<Nbit>> stores(N);
  vector<vector<int>> rewards(N, vector<int>(Npat));
  for(int i=0; i<N; i++){
    int buf;
    for(int b=0; b<Nbit; b++){
      cin >> buf;
      if(buf==1){ stores.at(i).set(b); }
    }
  }
  for(int i=0; i<N; i++){
    for(int j=0; j<Npat; j++){
      cin >> rewards.at(i).at(j);
    }
  }

  int ans= INT_MIN;
  for(int tmp=1; tmp<(1 << Nbit); tmp++){/* 全部閉めるのはNG */
    bitset<Nbit> mystore(tmp);
    int cand= 0;
    for(int i=0; i<N; i++){
      bitset<Nbit> both= stores.at(i) & mystore;
      cand+= rewards.at(i).at(both.count());
    }
    ans= max(ans, cand);
  }

  cout << ans << endl;
}