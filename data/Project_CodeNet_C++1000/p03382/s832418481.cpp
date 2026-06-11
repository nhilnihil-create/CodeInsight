#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  int *arr = new int[n];
  int p = 0;
  for (int i = 0; i < n; i++){
    cin >> arr[i];
    if (arr[i] > p){
      p = arr[i];
    }
  }
  int r = 0, temp = p;
  for (int i = 0; i < n;i++){
    if (abs(p - arr[i] * 2) < temp){
      r = arr[i];
      temp = abs(p - arr[i] *2);
    }
  }
  cout << p << " " << r;
  delete[] arr;
  return 0;
}