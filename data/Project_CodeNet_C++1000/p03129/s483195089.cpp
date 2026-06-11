#include<iostream>
using namespace std;

int main() {
  int N, K; cin >> N >> K;
  if (N%2 && N/2+1 >= K) cout << "YES" << endl;
  else if (N%2==0 && N/2 >= K) cout << "YES" << endl;
  else cout << "NO" << endl;
}