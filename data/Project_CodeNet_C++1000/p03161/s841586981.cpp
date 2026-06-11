#include <bits/stdc++.h>
using namespace std;
//NOT TO SUBMIT IN WRONG PLACE OR BY WRONG COMPILER
//educational dp contest, task b, 2020/09/14
//ms

/*
https://atcoder.jp/contests/dp
*/

#define BIG 100000000000

int main(void){
  int N, K;
  vector<int64_t> h;
  vector<int64_t> cost(100001);

  cin >>N >>K;
  for(int i=0;i<N;i++){
    int tmp;
    cin >>tmp;
    h.push_back(tmp);
  }

  cost[0]=0;
  for(int i=1;i<K;i++){
    cost[i]=BIG;
    for(int j=0;j<i;j++) cost[i]=min(abs(h[i]-h[j])+cost[j], cost[i]);
  }

  for(int i=K;i<N;i++){
    cost[i]=BIG;
    for(int j=i-K;j<i;j++) cost[i]=min(abs(h[i]-h[j])+cost[j], cost[i]);
  }

  cout <<cost[N-1]<<endl;

  return 0;
}
/*
n-1, n-2, ......, n-K番目までいく最小コストがそれぞれわかればn番目もわかる！
*/
