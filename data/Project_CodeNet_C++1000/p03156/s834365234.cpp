#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getResult(const vector<int> &points, const int questions,
              const int borderA, const int borderB){
  int i = 0;

  int lowerBorderA = 0;
  for(; (i < questions) && (points[i] <= borderA); i++){
    lowerBorderA++;
  }

  int betweenBorderAB = 0;
  for(; (i < questions) && (borderA + 1 <= points[i]) && (points[i] <= borderB); i++){
    betweenBorderAB++;
  }
  
  int upperBorderB = 0;
  for(; i < questions; i++){
    upperBorderB++;
  }
  
  return min({lowerBorderA, betweenBorderAB, upperBorderB});
}

int main(){
  int N, A, B;
  cin >> N >> A >> B;
  
  vector<int> P(N);
  for(int i = 0; i < N; i++){
    cin >> P[i];
  }
  sort(P.begin(), P.end());
  
  int result = getResult(P, N, A, B);
  cout << result;
  return 0;
}