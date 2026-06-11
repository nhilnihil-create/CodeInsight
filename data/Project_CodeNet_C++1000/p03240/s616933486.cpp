#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin>>n;
  vector<int> x(n),y(n),h(n);
  rep(i,n) cin>>x[i]>>y[i]>>h[i];
  int Hmax=0;
  rep(i,n) Hmax=max(Hmax,h[i]);
  rep(cx,101){
    rep(cy,101){
      for (int H=Hmax;H<Hmax+216;H++){
        bool flg=true;
        rep(i,n){
          if(h[i]!=max(H-abs(cx-x[i])-abs(cy-y[i]),0))flg=false;  
        }
        if(flg==true){
          cout<<cx<<" "<<cy<<" "<<H<<endl;
          return 0;
        }
      }
    }
  }
  return 0;
}

