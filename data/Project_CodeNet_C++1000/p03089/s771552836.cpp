#include <bits/stdc++.h>
using namespace std;

int main(){
  int N; cin >> N;
  vector<int> b(N);
  for(int i=0; i<N; i++) cin >> b[i];
  
  queue<vector<int>> q;
  q.push(b);
  bool f=false;
  vector<int> res(N);
  while(!q.empty()&&!f){
    vector<int> t=q.front(); q.pop();
    int s=t.size();
    if(s==1){
      if(t[0]==1){
        res[0]=1;
        f=true;
        break;
      }
    }else{
      for(int i=s-1; i>=0; i--){
        if(t[i]==i+1){
          vector<int> tt=t;
          res[s-1]=i+1;
          tt.erase(tt.begin()+i);
          q.push(tt);
          break;
        }
      }
    }
  }
  if(f){
    for(int i=0; i<N; i++){
      cout << res[i] << endl;
    }
  }else{
    cout << -1 << endl;
  }
}