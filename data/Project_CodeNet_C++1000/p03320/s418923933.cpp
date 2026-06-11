#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repeat(i,s,n) for(int (i)=s; (i)<(n); (i)++)
#define revrep(i,n) for(int (i)=(n)-1;i>=0; i--)

ll S(ll n) {
  int ret=0;
  while(n) {
    ret+=n%10;
    n/=10;
  }
  return ret;
}

void exp(int n) {
  repeat(i,1,n+1) {
      cout << i << " " << i*1.0/(S(i)*1.0) << endl;
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<setprecision(std::numeric_limits<float>::max_digits10);
//  int n;
//  cin>>n;
//  exp(n);
  int k;
  cin>>k;
  vector<ll> s;
  vector<ll> cs;
  repeat(i,1,1000) {
    ll x=i;
    cs.push_back(x);
    while(x<=1e15) {
      x*=10;
      x+=9;
      cs.push_back(x);
    }
  }
  sort(cs.begin(),cs.end());
  cs.erase(unique(cs.begin(),cs.end()), cs.end());
  int n = cs.size();
  rep(i,n) {
    bool f = true;
    repeat(j,i+1,n) {
      ll nn = cs[i];
      ll mm = cs[j];
      if(nn*S(mm)>mm*S(nn)) { // n/s(n)<=m/s(m) (where m>n)
        f=false;
        break;
      }
    }
    if(f) {
      s.push_back(cs[i]);
    }
  }
  // ll x=1;
  // rep(i,15) {
  //   ll y=0;
  //   rep(t,i) {
  //     y*=10;
  //     y+=9;
  //   }
  //   repeat(a,1,10) {
  //     s.push_back(a*x+y);
  //   }
  //   x*=10;
  // }
  rep(i,k) {
    // if(s[i]==0)
    //   cout << "s[" << i <<"]=" << s[i] << endl;
    cout << s[i] << endl;
  }
  return 0;
}
