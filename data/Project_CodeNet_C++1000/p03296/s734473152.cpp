#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll mod=1e9;

int main(){
  int N,A[100];
  cin>>N;
  for (int i(0);i<N;i++) cin>>A[i];
  int cnt(0);
  int now(A[0]);
  int cnti(1);
  for (int i(1);i<N;i++){
    if (A[i]==now){
      cnti++;
    }else{
      //cout << cnti << endl;
      cnt+=cnti/2;
      cnti = 1;
      now = A[i];
    }
  }
  cnt+=cnti/2;
  cout << cnt << endl;
}

