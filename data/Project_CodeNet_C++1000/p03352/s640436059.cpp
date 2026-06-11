#include <bits/stdc++.h>
// #include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=(a);i<(b);i++)
// #define sort(a) sort(a.begin(),a.end())
#define reverse(a) reverse(a.begin(),a.end())

template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}
const ll inf = 1LL<<60;

int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  int now=0,ans=0;

  int n;cin>>n;
  for(int i=1;i<=n;i++){
    now=0;
    for(int j=2;j<=1000;j++){
      now=pow(i,j);
      if (now<=n){
        ans=max(ans,now);
      }
    }
  }
  cout<<ans<<endl;
}
