#include <bits/stdc++.h>
using namespace std;


int main(){
  int64_t K;
  pair<int64_t,int64_t> M;
  M.first=2;
  M.second=2;
  cin >> K;
  vector<int64_t> A(K);
  for(int64_t i=0;i<K;i++){
    cin >> A.at(i);
  }
  for(int64_t i=K-1;i>=0;i--){
    if(M.second/A.at(i)!=M.first/A.at(i)||M.first%A.at(i)==0){
      M.first=A.at(i)*((M.first-1)/A.at(i)+1);
      M.second=A.at(i)*(M.second/A.at(i)+1)-1;
    }else{
      cout << -1 << endl;
      return 0;
    }
  }
  cout << M.first << " " << M.second << endl;
}
