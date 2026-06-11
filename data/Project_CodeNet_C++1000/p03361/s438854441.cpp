#include<bits/stdc++.h>
#define ll long long int
#define vec vector<ll>
#define mat vector<vec>

using namespace std;

const ll mod=1000000007;
const ll inf=LONG_LONG_MAX;
ll dx[4]={1,0,-1,0};
ll dy[4]={0,-1,0,1};
ll dx8[8]={1,0,-1,1,-1,1,0,-1};
ll dy8[8]={1,1,1,0,0,-1,-1,-1};

int main(){

  ll h,w;
  cin >> h >> w;

  char e[h+2][w+2];
  for(ll i=0;i<h+2;i++){
    for(ll j=0;j<w+2;j++){
      if(i==0 || i==h+1 || j==0 || j==w+1)e[i][j]='.';
      else cin >> e[i][j];
    }
  }

  bool ok=1;
  for(ll i=1;i<h+1;i++){
    for(ll j=1;j<w+1;j++){
      if(e[i][j]=='.')continue;
      bool ok2=0;
      for(ll k=0;k<4;k++)if(e[i+dx[k]][j+dy[k]]=='#')ok2=1;
      if(!ok2)ok=0;
    }
  }

  if(ok)cout << "Yes" << endl;
  else cout << "No" << endl;

}
