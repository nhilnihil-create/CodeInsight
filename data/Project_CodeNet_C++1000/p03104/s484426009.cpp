#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int main(){
  ll a, b;
  cin >> a >> b;
  if(a != 0){
    a--;
    ll sum = 0;
    for(ll i=1; i<=50; i++){
      ll cnt;
      ll bc = (b+1)/(ll)pow(2, i)*(ll)pow(2, i-1);
      if((b+1)%(ll)pow(2, i) > (ll)pow(2, i-1)) 
        bc += (b+1)%(ll)pow(2, i)-(ll)pow(2, i-1);
      ll ac = (a+1)/(ll)pow(2, i)*(ll)pow(2, i-1);
      if((a+1)%(ll)pow(2, i) > (ll)pow(2, i-1)) 
        ac += (a+1)%(ll)pow(2, i)-(ll)pow(2, i-1);
      cnt = bc - ac;
      if(cnt % 2 == 1) sum += (ll)pow(2, i-1);
    }
    cout << sum << endl;
  }else{
    ll sum = 0;
    for(ll i=1; i<=50; i++){
      ll cnt;
      ll bc = (b+1)/(ll)pow(2, i)*(ll)pow(2, i-1);
      if((b+1)%(ll)pow(2, i) > (ll)pow(2, i-1)) 
        bc += (b+1)%(ll)pow(2, i)-(ll)pow(2, i-1);
      cnt = bc;
      if(cnt % 2 == 1) sum += (ll)pow(2, i-1);
    }
    cout << sum << endl;
  }
  return 0;
}
