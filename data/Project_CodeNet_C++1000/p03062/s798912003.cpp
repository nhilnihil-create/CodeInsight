#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;
#define rep(i,s,n) for(int i=(int)(s);i<(int)(n);i++)


int main(){
  int N; cin >> N;
  ll sum = 0;
  ll cnt = 0;
  ll mn = 1000000000;
  for(int i=0;i<N;i++){
    ll x; cin >> x;
    if(x<0){
      x *= -1;
      cnt++;
    }
    sum += x;
    mn = min(mn,x);
  }
  if(cnt%2==1) sum -= 2*mn;
  cout << sum << endl;
}