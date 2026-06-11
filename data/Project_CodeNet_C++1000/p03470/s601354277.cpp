#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> d(N);
  for (int i = 0; i < N; i++) {
    cin >> d[i];  
  }
  sort(d.begin(), d.end());
  reverse(d.begin(), d.end());
  
  int m = *(d.begin());
  int count = 1;
  for (auto i = (d.begin() + 1); i != d.end(); i++) {
	if (m == *i)
      continue;
	m = *i;
    count++;
  }

  cout << count << endl;
}
