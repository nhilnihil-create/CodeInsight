#include <bits/stdc++.h>
using namespace std;

int main(){// a + b \geq a xor b より尺取法が使える。
  int N;
  cin >> N;

  vector<int64_t> data(N);
  for(int i=0; i<N; i++){
    cin >> data.at(i);
  }

  int64_t ans= 0;
  int64_t right= 0;
  int64_t sum_LR= 0;
  int64_t xor_LR= 0;
  for(int64_t left=0; left<N; left++){  
    while(right < N && sum_LR+ data.at(right)==(xor_LR^ data.at(right))){/* ビット演算の優先順位が低いので()をつけないとバグる */
      sum_LR+= data.at(right);
      xor_LR^= data.at(right);
      right++;
    }
    ans+= right- left;

    if(right==left){ right++; }
    else{
      sum_LR-= data.at(left);
      xor_LR^= data.at(left);
    }
  }

  cout << ans << endl;
}