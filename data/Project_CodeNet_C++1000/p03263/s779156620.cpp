#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
typedef pair<ll,ll> P;

int main() {
  int h,w;
  cin>>h>>w;
  vector<vector<int>> a(h,vector<int>(w));
  rep(i,h) {
    rep(j,w){
      cin >> a.at(i).at(j);
    }
  }
  
  vector<tuple<int,int,int,int>>ans;
  rep(i,h){
    if(i%2==0){
      rep(j,w-1){
        if(a[i][j]%2!=0){
          a[i][j+1]++;
          ans.push_back(make_tuple(i+1,j+1,i+1,j+2));
        }
      }
      if(i!=h-1&&a[i][w-1]%2!=0){
        a[i+1][w-1]++;
        ans.push_back(make_tuple(i+1,w,i+2,w));
      }
    }
    else{
      for(int j=w-1;j>0;j--){
        if(a[i][j]%2!=0){
          a[i][j-1]++;
          ans.push_back(make_tuple(i+1,j+1,i+1,j));
        }
      }
      if(i!=h-1&&a[i][0]%2!=0){
        a[i+1][0]++;
        ans.push_back(make_tuple(i+1,1,i+2,1));
      }
    }
  }
  cout<<ans.size()<<endl;
  rep(i,ans.size()){
    cout<<get<0>(ans[i])<<" "<<get<1>(ans[i])<<" "<<get<2>(ans[i])<<" "<<get<3>(ans[i])<<endl;
  }
}