#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int k;
  cin >> k;
  vector<ll> ak(k);
  for(int i=0; i<k; ++i) cin >> ak[i];
  ll ansl = 2, ansr = 2;
  for(int i=k-1; i>=0; --i){
    if(ansr < ak[i]){
      cout << -1 << endl;
      return 0;
    }
    ansl = ((ansl-1) /ak[i] +1)*ak[i];
    ansr = ansr /ak[i] *ak[i] +(ak[i]-1);
    if(ansr < ansl){
      cout << -1 << endl;
      return 0;
    }
    //cout << ansl << " " << ansr << endl;
  }
  cout << ansl << " " << ansr << endl;
}