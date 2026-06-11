#include <bits/stdc++.h>
 
#define rep(i, n) for (ll i=0;i<(n); i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define ALL(x) (x).begin(),(x).end()
 
using namespace std;
//using ll=long long;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pi;

const long double PI=3.14159265358979323846;

ll h,w;
ll ans;
//vector<char> masu;

template<class T> bool contain(const std::string& s, const T& v) {
   return s.find(v) != std::string::npos;
}


int main(){
  ll h,w,d;
  cin>>h>>w>>d;

  vector<pi> a(h*w+1);

  ll tmp;
  rep(i, h*w){
    cin >> tmp;
    ll ww = (i+1)%w;
    ll hh = (i+1)/w+1;
    if(ww==0) {
      ww=w;
      hh--;
    }
    
    a[tmp] = make_pair(hh, ww);
  }
  vector<ll> S(h*w+1+d);
  S[0] = 0;

  rep(i, d+1){
    S[i] = 0;
  }

  rep(i,h*w+1){
    ll j = i+1;
    if(j+d>h*w) break;
    S[j+d] = S[j] + abs(a[j+d].first-a[j].first) + abs(a[j+d].second-a[j].second) ;
}
  ll q,l,r;
  cin >>q;
  rep(i, q){
    cin >> l >>r;
    cout <<S[r]-S[l]<<endl;
  }
  
}
