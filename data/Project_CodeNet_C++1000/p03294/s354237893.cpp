// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;
  int sum = 0;
  for(int i = 0; i < N; i++) {
    int a;
    cin >> a;
    sum += (a - 1);
  }

  cout << sum << endl;

  return 0;
}
