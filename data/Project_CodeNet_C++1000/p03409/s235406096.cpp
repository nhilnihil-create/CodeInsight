#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<n+1;i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end())
typedef long long ll;

int main(){
  int n;
  cin >> n;
  vector<pair<int,int>> r(n);
  vector<pair<int,int>> b(n);
  rep(i,n){
    int x,y;
    cin >> x >> y;
    auto tmp = make_pair(y,x);
    r[i] = (tmp);
  }
  sort(r);
  reverse(r);
  rep(i,n){
    int x,y;
    cin >> x >> y;
    auto tmp = make_pair(x,y);
    b[i] = (tmp);
  }
  sort(b);
  vector<bool> seen(n,0);
  int ans = 0;
  rep(i,n){//i番目のb
    int x = b[i].first;//bのx座標
    int y = b[i].second;//bのy座標
    rep(j,n){//j番目のr
      if(r[j].second < x){//bより小さい
        if(seen[j]) continue;//ペアが出来てたらスキップ
        if(r[j].first < y){//bより小さい
          seen[j] = 1;
          ans ++;
          break;
        }
      }
    }
  }
  cout << ans << endl;
}