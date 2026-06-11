#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n,C;
  cin>>n>>C;
  int d[C][C];
  int c[n][n];
  rep(i,0,C){
    rep(j,0,C){
      cin>>d[i][j];
    }
  }
  rep(i,0,n){
    rep(j,0,n){
      cin>>c[i][j];
    }
  }
  int x[C],y[C],z[C];
  rep(i,0,C){
    x[i]=0;
    y[i]=0;
    z[i]=0;
  }
  rep(i,0,n){
    rep(j,0,n){
      if((i+j)%3==0){
        x[c[i][j]-1]++;
      }
      else if((i+j)%3==1){
        y[c[i][j]-1]++;
      }
      else{
        z[c[i][j]-1]++;
      }
    }
  }
  int p[C];
  rep(i,0,C){
    int cur=0;
    rep(j,0,C){
      cur+=x[j]*d[j][i];
    }
    p[i]=cur;
  }
  int q[C];
  rep(i,0,C){
    int cur=0;
    rep(j,0,C){
      cur+=y[j]*d[j][i];
    }
    q[i]=cur;
  }
  int r[C];
  rep(i,0,C){
    int cur=0;
    rep(j,0,C){
      cur+=z[j]*d[j][i];
    }
    r[i]=cur;
  }
  int ans=3e8;
  rep(i,0,C){
    rep(j,0,C){
      rep(k,0,C){
        if(i!=j && j!=k && k!=i){
          ans=min(ans,p[i]+q[j]+r[k]);
        }
      }
    }
  }
  cout<<ans<<endl;
}