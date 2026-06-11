#include<bits/stdc++.h>
using namespace std;

int sum(vector<int> A){
  int s = 0;
  for (int i = 0; i < A.size()-1; i++){
    s += A.at(i);
  }
  return s;
}

vector<int> input(int N){
  vector<int> vec(N);
  for (int i = 0; i < N; i++){
    cin >> vec.at(i);
  }
  return vec;
}



int main(){
  int N;
  cin >> N;

  vector<int>B = input(N);
  sort(B.begin(), B.end());
  
  int sumB = sum(B);

  int C;
  C = B.at(N-1)/2;

  cout << sumB + C << endl;
 
  
}
