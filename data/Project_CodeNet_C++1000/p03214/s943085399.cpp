#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, K;
  double sum = 0, avg = 0, cent = 100;
  cin >> N;
  vector<int> a(N);
  for(int i = 0; i < N; i++){
    cin >> a[i];
    sum += a[i];
  }
  avg = sum/N;
  for(int i = 0; i < N; i++){
    double tmp = abs(a[i] - avg);
    if(tmp < cent){
      cent = tmp;
      K = i;
    }
  }
/*
  vector<char> S(N);
  for(int i = 0; i < N; i++)
    cin >> S.at(i);
*/
  cout << K << endl;
}