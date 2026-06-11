#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long  ll;

int main(){
    int N; cin >> N;
	vector<ll> a(N);
  	rep(i, N) cin >> a[i];
  	vector<ll> b(N);
  	rep(i, N) cin >> b[i];

  	ll suma=0;
    ll sumb=0;

  	for(int i=0; i < N; i++) {
      suma += a[i];
      sumb += b[i];
    }
    ll m = sumb - suma;

    ll diff = 0;
    for(int i=0; i < N; i++) {
      if(a[i]<b[i]){
      	diff += (b[i] - a[i])/2 +(b[i] - a[i])%2;
        if(diff>m){
          cout << "No" << endl;
          return 0;
        }
      }
    }

    diff = 0;
    for(int i=0; i < N; i++) {
      if(a[i]>b[i]){
      	diff += a[i] - b[i];
        if(diff>m){
          cout << "No" << endl;
          return 0;
        }
      }
    }

    cout << "Yes" << endl;
    return 0;
}