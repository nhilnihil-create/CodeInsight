#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;

int main(){
  ll Q;
  cin >> Q;
  rep(i,Q){
    ll a,b,t;
    cin >> a >> b;
    if(a>b)swap(a,b);
    t=(ll)sqrt(a*b-1);
    while((t+1)*(t+1)<a*b) t++;
    while(t*t>=a*b)t--;
    if(a==b||a+1==b){
      cout << 2*a-2 << endl;
    }else if(t*(t+1)>=a*b){
      cout << 2*t-2 << endl;
    }else{
      cout << 2*t-1 << endl;
    }
  }
}