#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
  int N,A,B;
  cin >> N >> A >> B;
  cout << std::min(A,B) << " " << std::max(A+B-N,0) << endl;
  return 0;
}