#include <bits/stdc++.h>
using namespace std;

const int M = 5;
long long sum;

long long dfs(vector<long long> A, vector<long long> B){
  if(A.size() == 3){
    sum += B.at(A.at(0)) * B.at(A.at(1)) * B.at(A.at(2));
  }
  int prev_last;
  if(A.empty()) prev_last = 1;
  else prev_last = A.back() + 1;

  for(int i = prev_last; i <= M; i++){
    A.push_back(i);
    dfs(A, B);
    A.pop_back();
  }
  return sum;
}

int main(){
  long long N;
  cin >> N;
  long long cntM, cntA, cntR, cntC, cntH;
  cntM = 0;
  cntA = 0;
  cntR = 0;
  cntC = 0;
  cntH = 0;
  for(auto i = 0; i < N; i++){
    string S;
    cin >> S;
    if(S.at(0) == 'M') cntM++;
    else if(S.at(0) == 'A') cntA++;
    else if(S.at(0) == 'R') cntR++;
    else if(S.at(0) == 'C') cntC++;
    else if(S.at(0) == 'H') cntH++;
  }
  vector<long long> A;
  vector<long long> B(6);
  B.at(1) = cntM;
  B.at(2) = cntA;
  B.at(3) = cntR;
  B.at(4) = cntC;
  B.at(5) = cntH;
  long long ans = dfs(A, B);
  cout << ans << endl;
}
