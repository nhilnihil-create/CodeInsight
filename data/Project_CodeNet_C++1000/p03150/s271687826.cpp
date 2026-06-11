#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  string S;
  cin >> S;
  int N=S.size();
  for(int i=0;i<=7;i++){
    string T=S;
    T.erase(i,N-7);
    if(T=="keyence"){
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}