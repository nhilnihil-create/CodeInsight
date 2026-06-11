#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const int inf=1<<30;

int main(){
  int n,m;
  cin >> n >> m;
  vector<ll> x(n);
  vector<ll> y(n);
  vector<ll> z(n);
  rep(i,n){
    cin >> x[i] >> y[i] >> z[i];
  }
  vector<ll> v(n);
  priority_queue<ll> q;
  //1
  rep(i,n) v[i]=x[i]+y[i]+z[i];
  sort(all(v));
  reverse(all(v));
  ll sum=0;
  rep(i,m) sum+=v[i];
  q.push(sum);
  //2
  rep(i,n) v[i]=-x[i]+y[i]+z[i];
  sort(all(v));
  reverse(all(v));
  sum=0;
  rep(i,m) sum+=v[i];
  q.push(sum);
  //3
  rep(i,n) v[i]=x[i]-y[i]+z[i];
  sort(all(v));
  reverse(all(v));
  sum=0;
  rep(i,m) sum+=v[i];
  q.push(sum);
  //4
  rep(i,n) v[i]=x[i]+y[i]-z[i];
  sort(all(v));
  reverse(all(v));
  sum=0;
  rep(i,m) sum+=v[i];
  q.push(sum);
  //5
  rep(i,n) v[i]=-x[i]-y[i]+z[i];
  sort(all(v));
  reverse(all(v));
  sum=0;
  rep(i,m) sum+=v[i];
  q.push(sum);
  //6
  rep(i,n) v[i]=-x[i]+y[i]-z[i];
  sort(all(v));
  reverse(all(v));
  sum=0;
  rep(i,m) sum+=v[i];
  q.push(sum);
  //7
  rep(i,n) v[i]=x[i]-y[i]-z[i];
  sort(all(v));
  reverse(all(v));
  sum=0;
  rep(i,m) sum+=v[i];
  q.push(sum);
  //8
  rep(i,n) v[i]=-x[i]-y[i]-z[i];
  sort(all(v));
  reverse(all(v));
  sum=0;
  rep(i,m) sum+=v[i];
  q.push(sum);
  cout << q.top() << endl;
}