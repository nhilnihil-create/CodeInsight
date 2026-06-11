#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> a(N);
  int minNumIndex,maxNumIndex;
  rep(i,N){
    cin >> a[i];
    if(i == 0){
      minNumIndex = i;
      maxNumIndex = i;
    }else{
      if(a[i] < a[minNumIndex])   minNumIndex = i;
      if(a[i] >= a[maxNumIndex])  maxNumIndex = i;
    }
  }
  cout << 2*N-1 << "\n";
  if(abs(a[minNumIndex]) >= abs(a[maxNumIndex])){
    rep(i,N){
      cout << minNumIndex +1<< ' ' << i +1<< "\n";
    }
    for(int i = N-1; i >= 1; i--) {
      cout << i +1<< ' ' << i-1 +1<< "\n";
    }

  }else{
    rep(i,N){
      cout << maxNumIndex +1<< ' ' << i +1<< "\n";
    }
    rep(i,N-1){
      cout << i +1<< ' ' << i+1 +1<< "\n";
    }
  }

  return 0;
}
