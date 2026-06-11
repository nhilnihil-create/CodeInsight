#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const int inf=1<<30;

int main(){
  int n; cin >> n;
  if(n%2==0){
    int m=n*(n-1)/2-n/2;
    cout << m << endl;
    for(int i=1;i<=n;i++){
      for(int j=i+1;j<=n;j++){
        if(i+j==n+1) continue;
        cout << i << " " << j << endl;
      }
    }
  }
  else{
    int m=n*(n-1)/2-(n-1)/2;
    cout << m << endl;
    for(int i=1;i<=n;i++){
      for(int j=i+1;j<=n;j++){
        if(i+j==n) continue;
        cout << i << " " << j << endl;
      }
    }
  }
  
}