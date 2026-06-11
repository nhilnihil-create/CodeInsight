#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  vector<int> S(4);
  for(int i=0;i<4;i++){
    cin >> S[i];
  }
  sort(S.begin(),S.end());
  if(S.size()==4 && S[0]==1 && S[1]==4 && S[2]==7 && S[3]==9){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
}