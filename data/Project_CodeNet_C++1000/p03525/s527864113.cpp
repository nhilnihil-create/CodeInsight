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

int dcnt[13];

int main(){
  int n; cin >> n;
  rep(i,n){
    int d; cin >> d;
    dcnt[d]++;
  }
  vector<int> c1(0);
  vector<int> v={0,24};
  rep(i,13){
    if((i==0&&dcnt[i]>0)||dcnt[i]>=3){
      cout << 0 << endl;
      return 0;
    }
    else if(dcnt[i]==1){
      c1.push_back(i);
    }
    else if(dcnt[i]==2){
      v.push_back(i);
      v.push_back(24-i);
    }
  }
  int l=c1.size();
  int ans=0;
  for(int i=0;i<(1<<l);i++){
    vector<int> v2=v;
    rep(j,l){
      if(i&(1<<j)) v2.push_back(c1[j]);
      else v2.push_back(24-c1[j]);
    }
    sort(all(v2));
    int diff=inf;
    rep(i,v2.size()-1){
      chmin(diff,v2[i+1]-v2[i]);
    }
    chmax(ans,diff);
  }
  cout << ans << endl;
}