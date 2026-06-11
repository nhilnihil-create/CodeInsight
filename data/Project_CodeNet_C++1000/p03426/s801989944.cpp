#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int px[90010],py[90010];
int rui[90010];

int main(){
  int h,w,d;
  cin >> h >> w >> d;
  //vector<ll> px(h*w,0),py(h*w,0);
  for(int i=0;i<h;++i){
    for(int j=0;j<w;++j){
      int a;
      cin >> a;
      px[a]=i;
      py[a]=j;
    }
  }
  //vector<ll> rui(h*w,0);
  for(int i=d+1;i<=h*w;++i){
    rui[i]=rui[i-d]+abs(px[i]-px[i-d])+abs(py[i]-py[i-d]);
  }
  int q;
  cin >> q;
  vector<ll> ans;
  for(int i=0;i<q;++i){
    int l,r;
    cin >> l >> r;
    //cout << rui[r]-rui[l] << endl;
    ans.push_back(rui[r]-rui[l]);
  }
  for(int i=0;i<q;++i){
    cout << ans[i] << endl;
  }
  return 0;
}
