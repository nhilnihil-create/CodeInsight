#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  int n,a,b;
  cin>>n>>a>>b;
  int cnt=0;
  for(int i=1;i<n+1;i++){
    int g=i;
    int s=0;
    for(int j=5;j>=0;j--){
      s+=g/int(pow(10,j));
      g-=g/int(pow(10,j))*int(pow(10,j));
    }
    if(a<=s&&s<=b) cnt+=i;
  }
  cout<<cnt<<endl;
}