#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int N;
  cin >> N;
  int64_t first = 0;
  int64_t second = 2;
  int64_t answer = 1;
  for (int i=0;i < N - 1; i++){
  first = second;
  second = answer;
  answer = first + second;
 }
  printf("%ld",answer);

}