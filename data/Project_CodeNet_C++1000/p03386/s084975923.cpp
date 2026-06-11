#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, K;
  cin >> A >> B >> K;
  vector<int> vec;
  for (int i = A; i <= B; i++) {
      if(i<=A+K-1||B-K+1<=i) vec.push_back(i);
  }
  sort(vec.begin(), vec.end());
  for (int i = 0; i < vec.size(); i++) {
      if(i!=0&&vec.at(i-1)==vec.at(i)) continue;
      cout << vec.at(i) << endl;
  }
}
