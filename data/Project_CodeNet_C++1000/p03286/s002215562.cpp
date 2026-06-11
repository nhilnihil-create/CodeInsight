#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll N;
  cin >> N;
  vector<int> S;
  if(N==0){
    cout << 0 << endl;
    return 0;
  }
  while(N!=0){
    S.push_back(abs(N)%2);
    N-=abs(N)%2;
    N/=-2;
  }
  for(int i=(int)S.size()-1;i>=0;--i){
    cout << S[i];
  }
  cout << endl;
}