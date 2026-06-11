#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#define M  300000

int turn_members(string S, int sum[]){
  int num=0;

  return num;
}
int main(){
  // sum[i] : 0~i-1までのEの累積人数
  int N, i, min, val, sum[M]={0}, me=0;
  string S;
  cin >> N;
  cin >> S;
  min = N;
  for (i = 0; i < N; i++){
    if (S.at(i) == 'E')
       sum[i+1] = sum[i] + 1;
    else
      sum[i+1] = sum[i];
  }
  for (i = 0; i < N; i++){
    if (S.at(i) == 'E')
      me = 1;
    val = (i - sum[i]) + (sum[N] - sum[i+1]);
    if (min > val)
      min = val;

  }

  cout << min << endl;
  return 0;
}
