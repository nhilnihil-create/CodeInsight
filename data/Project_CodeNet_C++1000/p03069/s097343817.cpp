#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <deque>

int main(){
  int N;
  scanf("%d", &N);
  std::string S;
  std::cin >> S;
  std::vector<int > leftblack(N+4), rightwhite(N+4);
  // leftblack: index=i未満の黒石の合計数
  // rightwhite: index=i以上の白石の合計数
  leftblack[0]= 0;
  rightwhite[N] = 0;
  for (int i=1; i<=N; i++){
    leftblack[i] = leftblack[i-1];
    if (S[i-1]=='#') leftblack[i]++;
  }
  for (int i=N-1; i>=0; i--){
    rightwhite[i]=rightwhite[i+1];
    if (S[i]=='.') rightwhite[i]++;
  }
  
  int ans = 2*N;
  for (int i=0; i<=N; i++){
    ans = std::min(ans, leftblack[i]+rightwhite[i]);
  }
  printf("%d\n", ans);
  return 0;
}
