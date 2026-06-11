#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N; cin >>N;
  vector<int> M(N);
  for(int i=0;i<N;i++){
    cin >> M[i];
  }
  sort(M.begin(),M.end());
  int sum=M[0];int x=0;
  for(int i=1;i<N+1;i++){
    if(sum==M[i]){
      sum=M[i];
      x++;
    }
    else if(sum<M[i]){
      sum=M[i];
    }
  }
  cout <<N-x<<endl;
}