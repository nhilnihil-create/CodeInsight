#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> b(N);
  for(int i=0;i<N;i++){
    cin >> b.at(i);
  }
  stack<int> ans;
  while(true){
    int rem=-1;
    if(b.empty()){
      break;
    }
    for(int i=0;i<b.size();i++){
      if(b.at(i)==i+1){
        rem=i;
      }
    }
    if(rem==-1){
      cout << -1 << endl;
      return 0;
    }
    ans.push(b.at(rem));
    b.erase(b.begin()+rem);
  }
  while(!ans.empty()){
    cout << ans.top() << endl;
    ans.pop();
  }
  return 0;
}
