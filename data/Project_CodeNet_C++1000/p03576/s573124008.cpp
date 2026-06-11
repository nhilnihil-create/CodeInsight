#include<queue>
#include<stack>
#include<math.h>
#include<cmath>
#include<bitset>
#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<utility>
#include<functional>
#include<deque>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
template<typename T>
vector<T> zaatsu(vector<T> &c1){
  vector<T> vals;
  int n=(int)c1.size();
  for(int i=0;i<n;i++){
    for(T d=0;d<=1;d++){
      vals.push_back(c1[i]+d);
    }
  }
  sort(vals.begin(),vals.end());
  vals.erase(unique(vals.begin(),vals.end()),vals.end());
  for(int i=0;i<n;i++){
    c1[i]=lower_bound(vals.begin(),vals.end(),c1[i])-vals.begin();
  }
  return vals;
}
int main(){
  ll n,k,i,j,l,m;
  cin >> n >> k;
  vector<ll> x1(n),y1(n);
  for(i=0;i<n;i++){
    cin >> x1[i] >> y1[i];
  }
  vector<ll> x=zaatsu(x1);
  vector<ll> y=zaatsu(y1);
  ll a[110][110],s[110][110];
  for(i=0;i<=x.size();i++){
    for(j=0;j<=y.size();j++){
      s[i][j]=0,a[i][j]=0;
    }
  }
  for(i=0;i<n;i++){
    a[x1[i]][y1[i]]++;
  }
  for(i=0;i<x.size();i++){
    for(j=0;j<y.size();j++){
      s[i+1][j+1]=s[i+1][j]+s[i][j+1]-s[i][j]+a[i][j];
    }
  }
  ll ans=5000000000000000000;
  for(i=0;i<x.size();i++){
    for(j=0;j<y.size();j++){
      for(l=i+1;l<=x.size();l++){
        for(m=j+1;m<=y.size();m++){
          if(s[l][m]+s[i][j]-s[l][j]-s[i][m]>=k){
            ans=min(ans,(x[l-1]-x[i])*(y[m-1]-y[j]));
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}