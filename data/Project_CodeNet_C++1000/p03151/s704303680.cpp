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

int main(){
  int N; cin >> N;
  int D[N];
  rep(i,N) cin >> D[i];
  int d;
  rep(i,N) {
    cin >> d;
    D[i] -= d;
  }
  sort(D, D+N);

  ll ntot = 0;
  rep(i,N){
    if (D[i]>=0) break;
    ntot += D[i];
  }

  int j = N-1;
  int j0 = lower_bound(D,D+N,0) - D;
  while (j>=j0 && ntot<0) {
    ntot += D[j];
    j--;
  }
  
  if (ntot<0) cout << -1 << endl;
  else {
    int retval = j0 + N - 1 - j;
    cout << retval << endl;
  }



  // cout << fixed << setprecision(10);
  
  return 0;
}
