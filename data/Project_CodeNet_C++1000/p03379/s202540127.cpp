#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int> 

set<int> divs(int n){
  set<int> retset;
  for (int i=1;i<=(int)sqrt(n);i++){
    if (n%i==0){
      retset.insert(i);
      retset.insert(n/i);
    }
  }
  return retset;
}

int main(){
  int N; cin >> N;
  int X[N], Y[N];
  rep(i,N) {
    cin >> X[i];
    Y[i] = X[i];
  }

  sort(Y, Y+N);
  int mp = Y[N/2-1], mn = Y[N/2];
  rep(i,N){
    if (X[i]>=mn) cout << mp << endl;
    else cout << mn << endl;
  }

  

  return 0;
}