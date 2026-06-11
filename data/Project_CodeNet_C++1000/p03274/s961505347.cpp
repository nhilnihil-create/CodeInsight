#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K;
  cin >> N >> K;
  if(K==1){
    int64_t mi=1e9;
    for(int i=0;i<N;i++){
      int x;
      cin >> x;
      if(mi>abs(x)){
        mi=abs(x);
      }
    }
    cout << mi << endl;
  }else{
    queue<int64_t> que;
    for(int i=0;i<K-1;i++){
      int x;
      cin >> x;
      que.push(x);
    }
    int64_t mi=1e18;
    for(int i=0;i<N-K+1;i++){
      int64_t x;
      cin >> x;
      int64_t res=abs(x-que.front())+min(abs(x),abs(que.front()));
      if(res<mi){
        mi=res;
      }
      que.pop();
      que.push(x);
    }
    cout << mi << endl;
  }
  return 0;
}
