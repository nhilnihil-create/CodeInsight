#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  // dp1[i]: 上からi桁目まで最大 N以下確定
  // dp2[i]: N以下未確定
  string S; cin >> S;
  int N = S.size();

  vector<int> dp1(N, 0);
  vector<int> dp2(N, 0);

  int d0 = S[0] - '0';
  for(int i = 0; i <= d0; i++){
    if(i == d0){
      dp2[0] = i;
    } else { 
      dp1[0] = max(dp1[0], i);
    }
  }

  for(int i = 0; i < N-1; i++){
    int d = S[i+1] - '0';
    for(int j = 0; j <= d; j++){
      if(j == d){
        dp2[i+1] = dp2[i] + d; 
      } else { 
        dp1[i+1] = max(dp1[i+1], dp1[i] + j);
      }
    }
  }

  for(int i = 0; i < N-1; i++){
    int d = S[i+1] - '0';
    for(int j = 0; j <= 9; j++){
      dp1[i+1] = max(dp1[i+1], dp1[i] + j);
    }
  }

  cout << max(dp1[N-1], dp2[N-1]) << endl;
}

