#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

struct p{
  int x; int y; char c;
  bool operator<(const p &a)const{
    return x < a.x;
  }
};

int main(){
  int n;
  cin>>n;
  vector<p> s(2*n);
  rep(i,n){
    int x,y;
    cin>>x>>y;
    s[i].x = x; s[i].y = y; s[i].c = 'r';
  }
  rep(i,n){
    int x,y;
    cin>>x>>y;
    s[n+i].x = x; s[n+i].y = y; s[n+i].c = 'b';
  }
  sort(s.begin(),s.end());
  
  vector<pair<int,int>> res;
  int ans = 0;
  
  rep(i,2*n){
    if(s[i].c == 'r'){
      res.pb({s[i].y,s[i].x});
      sort(res.begin(),res.end());
    }else{
      for(int j = res.size()-1;j>=0;j--){
        if(res[j].first < s[i].y){
          ans++;
          res[j].first = 2*n+1;
          break;
        }
      }
    }
  }
  cout << ans << endl;
}