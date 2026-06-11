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
  int N, K; cin >> N >> K;
  int h[N]; rep(i,N) cin >> h[i];

  sort(h,h+N);

  int retval = 1000000009;
  rep(i,N-K+1) retval = min(retval, h[i+K-1]-h[i]);

  cout << retval << endl;



  

  // cout << fixed << setprecision(6);
  return 0;
}

