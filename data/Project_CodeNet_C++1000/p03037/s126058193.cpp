#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin >> N >> M;
  vector<int> L(M),R(M);
  for(int i=0;i<M;i++){
    cin >> L.at(i) >> R.at(i);
  }
  sort(L.rbegin(),L.rend());
  sort(R.begin(),R.end());
  cout << max(R.at(0)-L.at(0)+1,0) << endl;
}
  