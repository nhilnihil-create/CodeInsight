#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,i,j,ans = 0;cin >> n;
  vector<pair<int,int>> r(n),b(n);int rs=n;
  for(i=0;i<n;i++) cin >> r[i].second >> r[i].first;
  for(i=0;i<n;i++) cin >> b[i].first >> b[i].second;
  sort(r.begin(),r.end(),greater<pair<int,int>>());sort(b.begin(),b.end());//red y,x blue x,y
  for(i=0;i<n;i++){
    for(j=0;j<rs;j++){
      if(b[i].first > r[j].second && b[i].second > r[j].first){
        ans++;r.erase(r.begin()+j);rs--;break;
      }
    }
  }
  cout << ans << endl;
}