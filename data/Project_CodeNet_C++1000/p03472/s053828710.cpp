#include <bits/stdc++.h>
using namespace std;

int main() {
  //input
  int N, H;
  cin >> N >> H;

  vector<int> A(N);
  vector<int> B(N);
  
  for (int i = 0; i < N; i++){
    cin >> A.at(i);
    cin >> B.at(i);
  }
  
    sort(A.begin(), A.end()); // {1, 2, 2, 5}
    sort(B.begin(), B.end()); // {1, 2, 2, 5}

  //count
  int count = 0;

  //Attack B
    for (int i = 0; i < N; i++) {
      if(B.at(N-1-i) >= A.at(N-1)){
        H -= B.at(N-1-i);
        count++;
      }
      
      if (H <= 0){
        break;
      }
    }
  
  //Attack A
    while (H > 0){
      H -= A.at(N-1);
      count++;
    }
  
  cout << count << endl;
  
}
