#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,A,B;
  cin >> N >> A >> B;
  vector<int>P(N);
  int count1 = 0;
  int count2 = 0;
  int count3 = 0;
  for (int i = 0; i < N; i++) {
    cin >> P.at(i);
    if (P.at(i) <= A){
      count1++;
    }
    else if (P.at(i) <= B){
      count2++;
    }
    else {
      count3++;
    }
  }
  
  cout << min(count1,min(count2,count3)) << endl;
}
  