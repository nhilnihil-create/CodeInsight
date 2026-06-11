#include <bits/stdc++.h>
using namespace std;

vector<int64_t> memo(100, -1);

int64_t Luca(int N) {
  if (memo.at(N) !=-1) return memo.at(N);
  if (N==1) return 1;

  return memo.at(N) = Luca (N-1) + Luca (N-2);
}

int main(){
  int N;
  cin >> N;
  memo.at(0) = 2;
  memo.at(1) = 1;
  cout << Luca (N) << endl;
}
        
      