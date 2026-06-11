#include<bits/stdc++.h>
#define rep(i, s, n) for (int i=(s); i<(n); i++)
using namespace std;

bool G[100][100];

int main() {
  int a,b; cin>>a>>b;
  rep(i, 0, 100) {
    rep(j, 0, 100) {
      if (i<50) G[j][i]=true;
      else G[j][i]=false;
    }
  }

  int cnt=1;
  rep(i, 0, 26) {
    rep(j, 0, 50) {
      if (cnt==a) break;
      G[2*j+1][2*i+1]=false;
      cnt++;
    }
  }
  cnt=1;
  rep(i, 28, 49) {
    rep(j, 0, 50) {
      if (cnt==b) break;
      G[2*j+1][2*i]=true;
      cnt++;
    }
  }
  cout<<100<<" "<<100<<endl;
  rep(i, 0, 100) {
    rep(j, 0, 100) {
      if (G[j][i]) cout<<'#';
      else cout<<'.';
    }
    cout<<endl;
  }
}