#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;


int main(){
  int M, K;
  cin >> M >> K;
  int MM = 1 << M;

  if(K == 0){
    for(int i=0; i<MM; i++){
      if(i>0) cout << " ";
      cout << i << " " << i;
    }
    cout << endl;
  }else{
    if(M<=1 || MM <= K){
      cout << -1 << endl;
    }else{
      cout << K;
      for(int i=MM-1; i>=0; i--){
        if(i == K) continue;
        cout << " " << i;
      }
      cout << " " << K;
      for(int i=0; i<MM; i++){
        if(i == K) continue;
        cout << " " << i;
      }
      cout << endl;
    }
  }
  
  return 0;
}

