#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin >> N >> M;
  vector<vector<int>>data(M);
  for(int i=0;i<M;i++){
    int L;
    cin >> L;
    for(int j=0;j<L;j++){
      int x;
      cin >> x;
      x--;
      data.at(i).push_back(x);
    }
  }
  
  vector<int>tukuka(M);
  for(int i=0;i<M;i++){
    cin >> tukuka.at(i);
  }
  
  int ans=0;
  for (int tmp = 0; tmp < (1 << N); tmp++) {
    bool a=true;
    for(int j=0;j<M;j++){
      int count=0;
      for(int k=0;k<data.at(j).size();k++){
        if(((1<<data.at(j).at(k))&tmp)!=0) count++;
      }
      if(count%2!=tukuka.at(j)){
        a=false;
      }
    }
    if(a){
      ans++;
    }
  }
  cout << ans << endl;
}