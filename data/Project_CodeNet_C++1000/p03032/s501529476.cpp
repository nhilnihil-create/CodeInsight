#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N,K; cin >> N >> K;
  vector<ll> V(N);
  for(int i=0;i<N;i++){
    cin >> V[i];
  }
  ll Vmax = 0;
  for(int i=1;i<=min(N,K);i++){
    for(int j=0;j<=i;j++){
      vector<ll> Vcur;
      // j jewels from right side, i-j jewels from left side.
      for(int k=0;k<j;k++){
        Vcur.push_back(V[k]);
      }
      for(int k=0;k<i-j;k++){
        Vcur.push_back(V[N-1-k]);
      }
      sort(Vcur.begin(),Vcur.end());
      // Now you have i jewels. You can throw away up to K - i jewels.
      ll Vsum = 0;
      for(int k=0;k<Vcur.size();k++){
        if(Vcur[k]>=0){
          Vsum += Vcur[k];
        }else{
          if(k>=K-i){
            Vsum += Vcur[k];
          }
        }
      }
      Vmax = max(Vsum,Vmax);
    }
  }
  cout << Vmax << endl;
}