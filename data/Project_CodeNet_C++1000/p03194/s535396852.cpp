#include<bits/stdc++.h>
using namespace std;
int main(){
  long N, P;
  cin >> N >> P;
  unordered_map<long, int>e;
  if(N != 1){
    if(P == 1){
      e[1] = 1;
    }else{
      long i = 2;
      while(P % i == 0){
        if(e.find(i) != e.end()){
          e[i]++;
        }else{
          e[i]=1;
        }
        P = P / i;
      }
      i++;
      while(P != 1 && pow(i, N) <= P){
        while(P % i == 0){
          if(e.find(i) != e.end()){
            e[i]++;
          }else{
            e[i]=1;
          }
          P = P / i;
        }
        i += 2;
      }
    }

    long ans = 1;
    for(auto pair:e){
      if(pair.second >= N){
        ans = ans * pow(pair.first, pair.second / N);
      }
    }
    cout << ans << endl;
  }else{
    cout << P << endl;
  }
}