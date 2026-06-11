#include <bits/stdc++.h>
using namespace std;
#define fix10 cout << fixed << setprecision(10);
#define rep(i,n) for(int i=0; i<(int)(n);i++)

int main(){
  int n,K;
  cin >> n >> K;
  vector<pair<long,long>> p(n);
  rep(i,n){
    long x,y;
    cin >> x >> y;
    p.at(i).first = x;
    p.at(i).second = y;
  }
  sort(p.begin(),p.end());
  long ans = 1e18;
  ans *= 5;
  
  if(K == 2){
    rep(i,n-1){
      for(int j=i+1;j<n;j++){
        long x = abs(p.at(i).first - p.at(j).first);
        long y = abs(p.at(i).second - p.at(j).second);
        ans = min(ans,x*y);
      }
    }
    cout << ans << endl;
    return 0;
  }
  
  if(K == 3){
  rep(i,n-2){
    long sx,tx,sy,ty;
    for(int j=i+1;j<n-1;j++){
      for(int k=j+1;k<n;k++){
        /*if(k==j+1){
          sx = min(p.at(i).first,min(p.at(j).first,p.at(k).first));
          tx = max(p.at(i).first,max(p.at(j).first,p.at(k).first));
          sy = min(p.at(i).second,min(p.at(j).second,p.at(k).second));
          ty = max(p.at(i).second,max(p.at(j).second,p.at(k).second));
        }*/
        sx = min(p.at(i).first,min(p.at(j).first,p.at(k).first));
        tx = max(p.at(i).first,max(p.at(j).first,p.at(k).first));
        sy = min(p.at(i).second,min(p.at(j).second,p.at(k).second));
        ty = max(p.at(i).second,max(p.at(j).second,p.at(k).second));
        int count = 0;
        rep(l,n){
          long x = p.at(l).first;
          long y = p.at(l).second;
          if(sx <= x && x <= tx && sy <= y && y <= ty) count++;
        }
        if(count >= K){
          ans = min(ans,(ty-sy)*(tx-sx));
        }
      }
    }
  }
    cout << ans << endl;
    return 0;
  }
  
  rep(i,n-3){
    long sx,tx,sy,ty;
    for(int j=i+1;j<n-2;j++){
      for(int k=j+1;k<n-1;k++){
        for(int a=k+1;a<n;a++){
        sx = min(min(p.at(i).first,p.at(a).first),min(p.at(j).first,p.at(k).first));
        tx = max(max(p.at(i).first,p.at(a).first),max(p.at(j).first,p.at(k).first));
        sy = min(min(p.at(i).second,p.at(a).second),min(p.at(j).second,p.at(k).second));
        ty = max(max(p.at(i).second,p.at(a).second),max(p.at(j).second,p.at(k).second));
        int count = 0;
        rep(l,n){
          long x = p.at(l).first;
          long y = p.at(l).second;
          if(sx <= x && x <= tx && sy <= y && y <= ty) count++;
        }
        if(count >= K){
          ans = min(ans,(ty-sy)*(tx-sx));
        }
        }
      }
    }
  }
  cout << ans << endl;
}