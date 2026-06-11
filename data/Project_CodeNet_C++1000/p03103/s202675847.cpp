#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N), B(N);
  vector<pair<int, int>> p(N);
  for(int i = 0; i < N; i++){
    cin >> A.at(i) >> B.at(i);
    p.at(i).first = A.at(i);
    p.at(i).second = B.at(i);
  }
  sort(p.begin(), p.end());
  long long kane = 0;
  int total = 0;
  
  for(int i = 0; i < N; i++){
    total += p.at(i).second;
    if(total >= M){
      kane += p.at(i).first * (long long)(p.at(i).second - (total - M));
      break;
    }
    else kane += p.at(i).first * (long long)p.at(i).second;
  }
  cout << kane << endl;
}