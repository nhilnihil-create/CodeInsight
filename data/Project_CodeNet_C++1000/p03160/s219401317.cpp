#include <bits/stdc++.h>
using namespace std;
//NOT TO SUBMIT IN WRONG PLACE OR BY WRONG COMPILER
//educational dp contest, task a, 2020/09/14
//ms,

/*
*/

int main(void){
  vector<int64_t> d(100000);
  vector<int> h(100000);
  int N;

  cin >>N;
  for(int i=0;i<N;i++) cin>>h[i];

  d[0]=0; d[1]=abs(h[1]-h[0]);
  for(int i=2;i<N;i++){
    d[i]=min(d[i-2]+abs(h[i-2]-h[i]), d[i-1]+abs(h[i-1]-h[i]));
  }

  cout <<d[N-1]<<endl;

  return 0;
}
/*
*/
