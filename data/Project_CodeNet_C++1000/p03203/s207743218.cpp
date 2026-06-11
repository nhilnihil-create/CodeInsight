#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)




int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int h,w,n;
  cin >> h >> w >> n;
  int ans = h;
  vector<pair<int,int>> cor(n);
  rep(i,n){
    cin >> cor[i].first >> cor[i].second;
  }
  sort(cor.begin(),cor.end());
  int offset = 0;
  rep(i,n){
    int x = cor[i].first;
    int y = cor[i].second;
    if(x==y+offset){
      offset++;
    }
    else if(x<y+offset+1) continue;
    else{
      ans = min(ans,x-1);
    }
  }
  cout << ans << endl;
  
  return 0;
    

}
