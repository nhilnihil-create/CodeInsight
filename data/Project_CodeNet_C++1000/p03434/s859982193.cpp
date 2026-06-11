#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, a = 0, b = 0, c;
  cin >> N;
  vector<int> F(N), A(N / 2 + 1), B(N / 2);
  
  for(int i = 0; i < N; i++)
    cin >> F.at(i);
  
  sort(F.begin(), F.end());
  reverse(F.begin(), F.end());
  
  for(int i = 0, j = 0; i < N; i += 2, j++)
    A.at(j) = F.at(i);
  
  for(int i = 1, j = 0; i < N; i += 2, j++)
    B.at(j) = F.at(i);
  
  for(int i = 0; i < N / 2 + 1; i++)
    a += A.at(i);
  
  for(int i = 0; i < N / 2; i++)
    b += B.at(i);
  
  c = a - b;
  
  cout << c << endl;
}