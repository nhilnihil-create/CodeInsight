#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;

  cin >> N >> M;
  vector<int> L(M);
  vector<int> R(M);

  for(int i=0;i<M;++i){
    cin >> L.at(i) >> R.at(i);
  }
  sort(L.begin(),L.end());
  sort(R.begin(),R.end());

  if(R.at(0)-L.at(M-1) >= 0){
    cout << R.at(0)-L.at(M-1)+1 << endl;
  }else{
    cout << 0 << endl;
  }
  return 0;
}
