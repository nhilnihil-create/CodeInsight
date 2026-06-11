#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  int max_num,min_num;
  cin >> N;
  cin >> max_num >> min_num;
  if(max_num < min_num) swap(max_num, min_num);
  
  for(int i = 2; i < N; i++){
    int number;
    cin >> number;
    if(number > max_num)
      max_num = number;
    else if(number < min_num)
      min_num = number;
  }
  cout << max_num - min_num << endl;
}