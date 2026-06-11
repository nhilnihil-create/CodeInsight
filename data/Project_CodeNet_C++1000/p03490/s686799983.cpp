#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define erep(i,a,n) for(int i = a;i<=n;i++)
typedef long long ll;
#define int long long
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 1101010101010101010
#define MOD 1000000007
#define P pair<int,int>
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }


signed main(){
  string s;
  cin >> s;
  int n = s.size();
  int x,y;
  cin >> x >> y;
  vint xary;
  vint yary;
  int cnt = 0;
  bool flag = true;
  rep(i,0,n){
    if(s[i] == 'T'){
      if(flag){
        xary.push_back(cnt);
        flag = false;
      }
      else{
        yary.push_back(cnt);
        flag = true;
      }
      cnt = 0; 
    }
    else if(s[i] == 'F'){
      cnt++;
    }
  }
  if(cnt > 0){
    if(flag){
        xary.push_back(cnt);
        flag = false;
      }
      else{
        yary.push_back(cnt);
        flag = true;
      }
  }
  /* rep(i,0,xary.size()){
    cout << xary[i] << endl;
  }
  cout << endl; */
  vector<set<int>> xans(11010);
  vector<set<int>> yans(11010);
  xans[0].insert(0);
  yans[0].insert(0);
  rep(i,0,xary.size()){
    if(i != 0){
      for(auto p:xans[i]){
        xans[i+1].insert(p+xary[i]);
        xans[i+1].insert(p-xary[i]);
      }
    }
    else if(i == 0){
      for(auto p:xans[i]){
        xans[i+1].insert(p + xary[i]);
      }
    }
  }
  rep(i,0,yary.size()){
    for(auto p:yans[i]){
      yans[i+1].insert(p+yary[i]);
      yans[i+1].insert(p-yary[i]);
    }
  }
  bool xflag = false;
  bool yflag = false;
  /* rep(i,0,xary.size()){
    for(auto p:xans[i]){
      cout << p << endl;
    }
    cout << endl;
  } */
  for(auto p:xans[xary.size()]){
    if(p == x) xflag = true;
  }
  for(auto p:yans[yary.size()]){
    if(p == y) yflag = true;
  }
  if(xflag && yflag) cout << "Yes" << endl;
  else cout << "No" << endl;
}