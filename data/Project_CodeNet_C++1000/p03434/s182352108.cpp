//#include <bits/stdc++.h>
#include<iostream>
using namespace std;

#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))

int main() {
  int N;
  cin >> N;

  int arr[N];
  for(int i = 0; i < N; i++) {
    cin >> arr[i];
  }
  
  sort(arr, arr + SIZE_OF_ARRAY(arr), greater<>());
  int alice_point = 0;
  int bob_point = 0;
  for(int i = 0; i < N; i++) {
    if(i % 2 == 0) {
      alice_point += arr[i];
    } else {
      bob_point += arr[i];
    }
  }
  cout << alice_point - bob_point << endl;
  
  return 0;
}
