#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

vector<vector<vector<int>>> F;
vector<vector<ll>> P;
int N;

ll max_val = -1000000000000000;

void solve(string S){
  if(S.size() < 10){
    solve(S+'0');
    solve(S+'1');
    return;
  }

  vector<int> Open(N,0);
  reverse(S.begin(), S.end());

  int num = 0;
  for(int j = 0; j < 5; j++){
    for(int k = 0; k < 2; k++){
      char c = S[j + 5 * k];

      if(c == '1'){ // 営業していたら
        num++; // 営業回数
        for(int i = 0; i < N; i++){
          if(F[i][j][k] == 1){ // 店iも営業していたら
            Open[i]++; // 被っている回数
          }
        }
      }
    }
  }

  if(num == 0) return;

  ll val = 0;

  for(int i = 0; i < N; i++){
    // cerr << "i: " << i << " open: " << Open[i] << endl;
    val += P[i][Open[i]];
  }

  // cerr << S << " num: " << num << " val: " << val << endl;
  max_val = max(max_val, val);

  return;
}

int main(){
  cout << setprecision(10);
  cin >> N;

  F.assign(N, vector<vector<int>>(5, vector<int>(2,0)));

  for(int i = 0; i < N; i++){
    for(int j = 0; j < 5; j++){
      for(int k = 0; k < 2; k++){
        cin >> F[i][j][k];
      }
    }
  }

  P.assign(N, vector<ll>(11,0));
  for(int i = 0; i < N; i++){
    for(int j = 0; j < 11; j++){
      cin >> P[i][j];
    }
  }

  solve("");

  cout << max_val << endl;

}
