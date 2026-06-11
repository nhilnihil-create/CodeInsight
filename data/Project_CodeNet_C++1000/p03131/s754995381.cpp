#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0;i < (n);i++)
#define all(v) v.begin(),v.end()
#define dec(x) cout << fixed << setprecision(x);
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vl>;


int main(){
  ll k,a,b; cin >> k >> a >> b;
  if(a+1 > k) cout << k+1 << endl;
  else if(b <= a+2) cout << k+1 << endl;
  else{
    if((k-a+1) % 2 == 1) cout << (k-a)*(b-a)/2 + 1 + a << endl;
    else cout << (k-a+1)*(b-a)/2 + a << endl;
  }
}