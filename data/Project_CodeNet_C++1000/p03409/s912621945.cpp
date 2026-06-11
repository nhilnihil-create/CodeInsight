#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = (int)(n)-1; i >=0; i--)

using ll = long long;

int main(){
  int n;
  cin>>n;
  vector<pair<int,int>> a(n),c(n);
  rep(i,n)cin>>a.at(i).second>>a.at(i).first;//x y red  yjiku
  rep(i,n)cin>>c.at(i).first>>c.at(i).second;//y x blue xjiku

  sort(a.begin(),a.end());//red;
  sort(c.begin(),c.end());//blue;
  //red y 軸で　降順
  reverse(a.begin(),a.end());

  int ans = 0;
  vector<int> seen(n);
  rep(i,n) seen.at(i) = 0;
  rep(i,n){
    rep(j,n){
      if(c.at(i).first>a.at(j).second&&c.at(i).second>a.at(j).first&&seen.at(j)==0){
        seen.at(j) = 1;
        ans++;
        break;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
