#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
using namespace std;
const int INF = 1001001001;
const int MOD = 1e9+7;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  ll a,b; cin >> a >> b;
  a--;
  if(a%2){
    a = ((a+1)/2)%2;
  }else{
    a ^= (a/2)%2;
  }
  if(b%2){
    b = ((b+1)/2)%2;
  }else{
    b ^= (b/2)%2;
  }
  cout << (a^b);
  cout << "\n";
  return 0;
}
