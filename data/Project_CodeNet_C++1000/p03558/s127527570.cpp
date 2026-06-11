#include<bits/stdc++.h>
#define MAX 100005
#define INF 1000000
using namespace std;
 
int main(){
  int k, a[MAX];
  deque<int> dq;
  scanf("%d", &k);
  for(int i = 0; i < MAX; i++) a[i] = INF;
  a[1] = 1; dq.push_front(1);
  while(!dq.empty()){
    int t = dq.front(); dq.pop_front();
    if(a[t*10%k] > a[t]){
      a[t*10%k] = a[t];
      dq.push_front(t*10%k);
    }
    if(a[(t+1)%k] > a[t] + 1){
      a[(t+1)%k] = a[t] + 1;
      dq.push_back((t+1)%k);
    }
  }
  printf("%d\n", a[0]);
}
