#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin>>n;
  vector<int> x(n), y(n), h(n);
  int res;
  rep(i,n){
    cin>>x[i]>>y[i]>>h[i];
    if(h[i]!=0) res = i;
  }
  
  rep(i,101)rep(j,101){
    int H=h[res]+abs(x[res]-i)+abs(y[res]-j);
    bool ok=true;
    rep(k,n){
      if(h[k]!=max(H-abs(x[k]-i)-abs(y[k]-j),0)){
        ok=false;
        break;
      }
    }
    
    if(ok){
      cout << i << ' ' << j << ' ' << max(H,1)<< endl;
      return 0;
    }
  }
}
