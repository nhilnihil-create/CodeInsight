#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin >> N;
  deque<int> dd,dt;
  for(int i=0;i<N;i++){
    int D;
    cin >> D;
    dd.push_back(D);
  }
  cin >> M;
  for(int i=0;i<M;i++){
    int T;
    cin >> T;
    dt.push_back(T);
  }
  sort(dd.begin(),dd.end());
  sort(dt.begin(),dt.end());
  while(1){
    if(dd.size()<dt.size()){
      cout << "NO" << endl;
      return 0;
    }
    if(dt.size()==0){
      break;
    }
    if(dd.front()==dt.front()){
      dd.pop_front();
      dt.pop_front();
    }else{
      dd.pop_front();
    }
  }
  cout << "YES" << endl;
  return 0;
}
