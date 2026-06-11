#include<bits/stdc++.h>
#define PI 3.141592653589
#define ll long long
using namespace std;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int  main(){
  ll n, x;
  cin >> n >> x;
  vector<ll> a(n);
  for(int i=0; i<n; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  int cnt = 0;
  for(int i=0; i<n; ++i){
    if(x>=a[i]) ++cnt, x-=a[i];
    else break;
  }
  if(cnt == n && x) --cnt;
  cout << cnt << endl;
  return 0;
}