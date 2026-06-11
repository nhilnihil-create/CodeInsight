#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int sum = 0;
  int N = 0;
    cin >> N;
  vector<int> data(N);
  for (int i = 0; i < N; i++) {
    cin >> data.at(i);
  }
  
  sort(data.begin(), data.end());
  
  for(int i = 0; i < N; i++) {
    sum += data.at(i);
    }
    sum -= data.at(N-1);
    
    if (sum > data.at(N-1)){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
}