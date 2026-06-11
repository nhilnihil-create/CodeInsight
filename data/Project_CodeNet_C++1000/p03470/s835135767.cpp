//#include <bits/stdc++.h>
#include<iostream>
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))

using namespace std;

int main() {
  int N;
  cin >> N;
  int mochi[N];
  for(int i = 0; i < N; i++) {
    cin >> mochi[i];
  }
  
  sort(mochi, mochi + SIZE_OF_ARRAY(mochi), greater<>());
  
  int count = 0;
  int prev = 999;
  for(int i = 0; i < N; i++) {
    if(mochi[i] < prev) {
      prev = mochi[i];
      count++;
    }
  }
  
  cout << count << endl;
}
