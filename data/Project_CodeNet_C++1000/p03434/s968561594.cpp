#include <iostream>
#include <vector>
using namespace std;

int main(){
  int N, A = 0, B = 0, max, max_data;
  cin >> N;
  vector<int> data(N);
  for (int i = 0; i < N; i++){
    cin >> data.at(i);
  }
  for (int i = 0; i < N; i++){
    if(i % 2 == 0){
      max = 0;
      max_data = 0; 
      for (int j = 0; j < N; j++){
        if (max < data.at(j)){
          max = data.at(j);
          max_data = j;
        }
      }
      A += max;
      data.at(max_data) = 0;
    }
    else{
      max = 0;
      max_data = 0; 
      for (int j = 0; j < N; j++){
        if (max < data.at(j)){
          max = data.at(j);
          max_data = j;
        }
      }
      B += max;
      data.at(max_data) = 0;
    }
  }
  cout << A - B;
  return 0;
}