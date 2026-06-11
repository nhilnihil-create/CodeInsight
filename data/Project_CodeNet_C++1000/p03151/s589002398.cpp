#include <bits/stdc++.h>
using namespace std;

int main () {
  int N;
  cin >> N;
  vector<long long>A(N);
  vector<long long>B(N);
  long long sumA = 0;
  long long sumB = 0;
  
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
    sumA += A.at(i);
  }
  for (int i = 0; i < N; i++) {
    cin >> B.at(i);
    sumB += B.at(i);
  }
  
  if (sumA < sumB){
    cout << -1 << endl;
    return 0;
  }
  
  long long dis = 0;
  long long add = 0;
  long long count = 0;
  vector<long long>plus(N,0);
  for (int i = 0; i < N; i++) {
    if (A.at(i) > B.at(i)){
      plus.at(i) = A.at(i) - B.at(i);
    }
    else if (A.at(i) < B.at(i)){
      dis += B.at(i) - A.at(i);
      count++;
    }
  }
  
  if (count == 0){
    cout << 0 << endl;
    return 0;
  }
  
  sort(plus.begin(), plus.end());
  reverse(plus.begin(), plus.end());
  
  for (int i = 0; i < N; i++) {
    add += plus.at(i);
    if (dis <= add){
      cout << count + i + 1 << endl;
      return 0;
    }
  }
}
    
    
    
  
  
  
  
   