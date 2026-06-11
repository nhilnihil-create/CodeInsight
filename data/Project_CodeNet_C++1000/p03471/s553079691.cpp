#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n,y;
  cin >> n >> y;
  int x=-1,yy=-1,z=-1;
  for(int i=0;i<=n;i++){
    for(int j=0;j<=n-i;j++){
      int k=n-i-j;
      if(10000*i+5000*j+1000*k==y){
        x=i;
        yy=j;
        z=k;
      }
    }
  }
  cout << x << " " << yy << " " << z;
      
}
