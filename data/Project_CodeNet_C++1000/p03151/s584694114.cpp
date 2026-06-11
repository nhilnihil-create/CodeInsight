#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T&a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T&a,T b){if(a>b){a=b;return 1;}return 0;}
const long long MOD = 1000000007;
typedef long long ll;

ll n;
string s,t;
ll a[100005],b[100005],c[100005];

int main() {
  cin >> n;
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];
  ll ans=0,sum=0; 
  rep(i,n){
    c[i]=a[i]-b[i];
    if(c[i]<0) ans++,sum+=c[i];
  }
  sort(c,c+n,greater<ll>());
  rep(i,n)if(c[i]>0 && sum<0) sum+=c[i], ans++;
  cout << (sum>=0 ? ans : -1) << endl;
}