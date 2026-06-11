#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
  int N;
  cin >> N;
  vector <int> a(N);
  for (int i = 0; i < N; i++) cin >> a[i];
  sort(a.begin(), a.end());
  int Alice = 0;
  int Bob = 0;
  for (int i = N-1; i >= 0; i-=2) {
    Alice += a[i];
  }
  for (int i = N-2; i >= 0; i-=2) {
    Bob += a[i];
  }
  cout << Alice-Bob << endl;
  return 0;
}
