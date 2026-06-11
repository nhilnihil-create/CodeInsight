#include <bits/stdc++.h>
using namespace std;

int abs(int x){

  if (x < 0){
    return -x;
  }else{
    return x;
  }
}

int main(){

  string S,remx = "";
  int nlis[100001],nind = 0;

  cin >> S;

  for (int i = 0 ; i < 100001 ; i++){
    nlis[i] = 0;
  }

  for (int i = 0 ; i < S.size() ; i++){

    if (S[i] != 'x'){
      remx += S[i];
      nind += 1;
    }else{
      nlis[nind] += 1;
    }

  }

  for (int i = 0 ; i < (remx.size()/2) ; i++){

    if (remx[i] != remx[remx.size()-1-i]){
      cout << -1 << endl;
      return 0;
    }

  }

  int ans = 0;

  for (int i = 0 ; i < ((remx.size()+1)/2) ; i++){

    ans += abs(nlis[i]-nlis[remx.size() - i]);

  }

  cout << ans << endl;
  return 0;
}

  
