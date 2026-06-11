#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll mod=1e9+7;

int main(){
  ll A,B,C;
  cin>>A>>B>>C;
  if (C-B>=0){
    if (C-A>=0){
      cout << B + min(C,((A+B)+1)) << endl;
    }else{
      cout << B+C << endl;
    }
  }else{
    cout << B+C << endl;
  }
  return 0;
}
