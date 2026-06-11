#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const int INT_INF = 2147483647;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int count(vector<int> p){
  vector<int> s;
  rep(i,24)if(p[i]==1)s.push_back(i);
  s.push_back(24);
  int res=24;
  rep(i,s.size()-1){
    chmin(res,s[i+1]-s[i]);
  }
  return res;
}

int main(){
  int n;
  cin >> n;
  int d[n];
  rep(i,n)cin >> d[i];
  vector<int> t(13,0);
  rep(i,n)t[d[i]]++;
  vector<int> a;
  vector<int>p(24,0);
  p[0]=1;
  if(t[0]>=1||t[12]>=2){
    cout << 0 << endl;
    return 0;
  }
  if(t[12]==1)p[12]=1;
  rep(i,11){
    if(t[i+1]>2){
      cout << 0 << endl;
      return 0;
    }
    if(t[i+1]==2)p[i+1]=1,p[24-i-1]=1;
    if(t[i+1]==1)a.push_back(i+1);
  }
  int ans=0;
  rep(i,1<<a.size()){
    vector<int>p2(24,0);
    copy(p.begin(), p.end(), p2.begin());
    rep(j,a.size()){
      if((i>>j)&1){
        p2[a[j]]=1;
      }else{
        p2[24-a[j]]=1;
      }
    }
    // rep(i,p2.size())cout << p2[i];
    // cout << endl;
    // cout << count(p2) << endl;
    chmax(ans,count(p2));
  }
  cout << ans << endl;
  return 0;
}
