#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, num, count;
  cin >> N;
  
  vector<int> vec(N);
  
  for (int i=0; i<N; i++) {
    cin >> vec.at(i);
  }
  
  sort(vec.begin(), vec.end()); //sort
  reverse(vec.begin(), vec.end());

  num = 0;
  count = 0;
  for (int i=0; i<N; i++) {
    count++;
    if (num == vec.at(i)) {
	  count--;
    }
    num = vec.at(i); // num に大きい方からvecを代入
  }
  cout << count << endl;
  
}