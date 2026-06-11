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

bool ok(long long x, long long n){
  int sum = 0;
  long long x_orig = x;
  while(x>0){
    sum+=x%10;
    x /= 10;
  }
  return sum+x_orig==n;
}

int main(){
  int N;
  scanf("%d", &N);
  std::vector<long long > A(N), B(N);
  std::multimap<long long, int, std::greater<long long > > sum;
  for (int i=0; i<N; i++){
    scanf("%lld", &A[i]);
    scanf("%lld", &B[i]);
    sum.insert(std::make_pair(A[i]+B[i], i));
  }
  long long Asum = 0;
  long long Bsum = 0;
  int counter = 0;
  for (auto &entry : sum){
    int index = entry.second;
    if(counter%2==0){
      Asum += A[index];
    } else {
      Bsum += B[index];
    }
    counter++;
  }
  std::cout << Asum-Bsum << std::endl;
  return 0;
}
