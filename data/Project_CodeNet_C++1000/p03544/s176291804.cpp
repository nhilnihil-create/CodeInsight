#include <bits/stdc++.h>
using namespace std;
 
static const int maxN = 86;

void Lucas(int N, vector<int64_t> &n){
  if(N == 0){
    n.at(0) = 2;
    return;
  } else if (N == 1){
    n.at(1) = 1;
    Lucas(0, n);
  } else {
    Lucas(N - 1, n);
    n.at(N) = n.at(N - 1) + n.at(N - 2);
  }
}

int main() {
  int N;
  cin >> N;
  vector<int64_t> n(N + 1);
  
  Lucas(N, n);
  cout << n.at(N) << endl;

}