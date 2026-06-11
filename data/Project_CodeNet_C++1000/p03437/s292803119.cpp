#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll x,y;
  cin >> x >> y;
  if(x%y==0){
    cout << "-1" << endl;
    return 0;
  }
  cout << x << endl;
  return 0;
}
