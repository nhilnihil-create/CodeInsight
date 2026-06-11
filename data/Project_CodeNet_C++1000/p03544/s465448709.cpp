#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

ll ans[100];


ll ryuka(int n){
  if(ans[n]!=0) return ans[n];
  ll ret;
  if(n==0){
    ans[n]=2;
    ret=2;
  }
  else if(n==1){
    ans[n]=1;
    ret=1;
  }
  else{
    ret=ryuka(n-1)+ryuka(n-2);
  }
  ans[n]=ret;
  return ret;
}


int main() {
  for(int i=0;i<100;i++)ans[i]=0;
 ll n;
  cin>>n;
  cout<<ryuka(n)<<endl;
}