#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> h(N);
  for(int i = 0; i<N; ++i) cin >> h.at(i);
  
  vector<int> dp(N,1001001000);
  
  dp.at(0) = 0;
  
  for(int i = 0; i<N; ++i){
    if(i>0){
      dp.at(i) = min(dp.at(i),
                       dp.at(i-1)+abs(h.at(i-1)-h.at(i))
                      );
    }
    if(i>1){
      dp.at(i) = min(dp.at(i),
                     dp.at(i-2)+abs(h.at(i-2)-h.at(i))
                    );
    }
  }
  
  cout << dp.at(N-1) << endl;
}
