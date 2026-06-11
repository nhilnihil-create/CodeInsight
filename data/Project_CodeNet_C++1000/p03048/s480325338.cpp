#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i <= (n) ; i ++ )
#define all(x) (x).begin(),(x).end()
using ll = long long;
using namespace std;

int main() {
  ll r,g,b,n;
  cin>>r>>g>>b>>n;
  int ans=0;
  rep(i,n/r){
     rep(j,n/g){
         if((n-i*r-j*g)>=0&&(n-i*r-j*g)%b==0){
           ans++;
         }
     }
  }
  cout <<ans<<endl;
}