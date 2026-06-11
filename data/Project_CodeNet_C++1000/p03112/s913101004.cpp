#include <bits/stdc++.h>

using namespace std;
const long long INF=1e18;

int main(){
  long long a, b, q, s[100009], t[100009];
  cin >> a >> b >> q;
  s[0]=-INF;
  t[0]=-INF;
  for(int i=1;i<=a;i++)cin >> s[i];
  for(int i=1;i<=b;i++)cin >> t[i];
  s[a+1]=INF;
  t[b+1]=INF;
  for(int i=0;i<q;i++){
    long long x; cin >> x;
    auto sub = upper_bound(s, s+a+2, x);
    auto tub = upper_bound(t, t+b+2, x);
    long long mn=INF;
    for(long long S: {*(sub-1), *sub}){
      for(long long T: {*(tub-1), *tub}){
        long long d1 = abs(S-x) + abs(T-S);
        long long d2 = abs(T-x) + abs(S-T);
        mn = min({mn, d1, d2});
      }
    }
    cout << mn << endl;
  }
}

