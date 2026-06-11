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
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  vector<int> b(0);
  while(a.size()){
    for(int i=a.size()-1;i>=0;i--){
      if(a[i]==i+1){
        b.push_back(a[i]);
        for(int j=i;j<a.size()-1;j++){
          swap(a[j],a[j+1]);
        }
        a.pop_back();
        break;
      }
      if(i==0&&a[i]!=i+1){
        cout << -1 << endl;
        return 0;
      }
    }
  }
  reverse(all(b));
  rep(i,b.size()){
    cout << b[i] << endl;
  }
  
}