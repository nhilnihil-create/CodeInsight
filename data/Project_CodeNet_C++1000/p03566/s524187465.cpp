#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repeat(i,s,n) for(int (i)=s; (i)<(n); (i)++)
#define revrep(i,n) for(int (i)=(n)-1;i>=0; i--)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<setprecision(std::numeric_limits<float>::max_digits10);
  int n;
  cin>>n;
  vector<int> t(n+2);
  vector<int> v(n+2);
  rep(i,n)cin>>t[i+1];
  rep(i,n)cin>>v[i+1];
  int T=0;
  vector<int> l(n+2);
  vector<int> r(n+2);
  rep(i,n) {
    l[i+1]=T;
    r[i+1]=T+t[i+1];
    T+=t[i+1];
  }
  double V=0;
  vector<double> maxv(400000);
  for(int tt=1; tt<=2*T; tt++) {
    double ttt = 0.5*tt;
    double pv=V;
    V+=0.5;
    rep(i,n+2) {
      if(ttt<l[i]) {
        V=min(V,v[i]+(l[i]-ttt));
      } else if(l[i]<=ttt&&ttt<=r[i]) {
        V=min(V,static_cast<double>(v[i]));
      } else {
        V=min(V,v[i]+(ttt-r[i]));
      }
    }
    maxv[tt]=V;
    //cout << "t="<<ttt<<",V="<<V<<endl;
  }
  maxv[2*T]=0;
  V = 0;
  for(int tt=2*T-1; tt>=0;tt--) {
    double ttt=0.5*tt;
    double pv = V;
    V+=0.5;
    rep(i,n+2) {
      if(ttt<l[i]) {
        V=min(V,v[i]+(l[i]-ttt));
      } else if(l[i]<=ttt&&ttt<=r[i]) {
        V=min(V,static_cast<double>(v[i]));
      } else {
        V=min(V,v[i]+(ttt-r[i]));
      }
    }
    maxv[tt]=min(maxv[tt],V);
  }
  double ans=0;
  repeat(tt, 1,2*T+1) {
    ans+=(maxv[tt]+maxv[tt-1])*0.5*0.5;
    //cout << 0.5*tt<< " " << maxv[tt]<<endl;
  }
  cout << ans << endl;
  return 0;
}
