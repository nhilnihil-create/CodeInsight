#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,X;
  cin >> N >> X;
  
  vector<int> amount(N);
  for(int i=0; i < N; i++){
    cin >> amount.at(i);
  }
  
  int min = 1000;
  int sum = 0;
  for(int i = 0; i < N ; i++){
    if(min > amount.at(i)){
      min = amount.at(i);
    }
    sum += amount.at(i);
  }
  
  int dounats = (X-sum)/min + N;
  
  cout << dounats << endl;
  
}