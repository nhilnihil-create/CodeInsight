#include<bits/stdc++.h>
using namespace std;
int main() {
  int N; cin >> N;
  vector<long long> stock(0);
  map<long long, long long> m;
  long long A = 0;
  for(int i = 0; i< N; i++) {
    long long a; cin >> a;
    A += a;
    if(m.count(A)) {
      m.at(A)++;
      continue;
    }
    m[A] = 1;
    stock.push_back(A);
  }
  if(m.count(0)) m.at(0)++;
  long long count = 0;
  for(int i = 0; i < stock.size(); i++) {
    long long x = m.at(stock.at(i));
    count += x * (x - 1) / 2;
  }
  cout << count << endl;
}