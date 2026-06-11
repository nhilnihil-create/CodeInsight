#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  vector<int> vector(N);
  rep(i, N){
  	cin >> vector.at(i);
  }
  sort(vector.begin(), vector.end());
  reverse(vector.begin(), vector.end());
  int sum = 0;
  rep(i, N){
    if(i % 2 == 0){
    	sum += vector.at(i);
    }
    if(i % 2 == 1){
    	sum -= vector.at(i);
    }
  }
  cout << sum << endl;
}