#include <bits/stdc++.h>
using namespace std;

int main(){
  float N, K;
  cin >> N >> K;
  cout << ceil((N - K)/(K - 1)) + 1 << endl;

}