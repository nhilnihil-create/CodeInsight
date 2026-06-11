#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll N;
  cin >> N;
  ll S,T;
  S=N/10;
  T=N-N/1000*1000;
  if(S%111==0 || T%111==0){
    cout << "Yes" << endl;
    return 0;
  }
  else{
    cout << "No" << endl;
    return 0;
  }
}