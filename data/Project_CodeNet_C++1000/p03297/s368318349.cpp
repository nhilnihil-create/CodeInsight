#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld,int> P;
constexpr ld pi = acos(-1.0);

// gcd(a, b)
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t;cin>>t;
    while(t--){
      // 始め, 消費, 閾値, 供給
      ll a,b,c,d;cin>>a>>b>>c>>d;
      if(b>a){
        cout<<"No"<<endl;
        continue;
      }
      if(b>d){
        cout<<"No"<<endl;
        continue;
      }
      if(c>=b){
        cout<<"Yes"<<endl;
        continue;
      }
      // b<=a, b<=d, c<b
      ll g=gcd(b,d);
      if(b-g+(a%g)>c) cout<<"No"<<endl;
      else cout<<"Yes"<<endl;
    }
}
