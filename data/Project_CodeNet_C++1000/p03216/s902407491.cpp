#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;
  int Q; cin >> Q;
  vector<long long> answer;
  for (int q=0; q<Q; q++){
    int k; cin >> k;
    long long D=0, M=0, DM=0, ans=0;
    for (int i=0; i<N; i++){
      if (S[i]=='D'){
        D++;
      } else if (S[i]=='M'){
        M++;
        DM += D;
      } else if (S[i]=='C'){
        ans += DM;
      }
      if (i>=k-1){
        if (S[i-k+1]=='D'){
          DM -= M;
          D--;
        } else if (S[i-k+1]=='M'){
          M--;
        }
      }
    }
    answer.push_back(ans);
  }
  for (auto k: answer) cout << k << endl;
}
