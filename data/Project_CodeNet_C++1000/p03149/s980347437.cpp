#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;
int main() {

  int N , M , L , O ;
  cin >> N >> M >> L >> O ;
  //vector<int> A(N) ;
  //rep(i,N) cin >> A.at(i) ;
  map<int,int> mp ;
  mp[N]++ ;
  mp[M]++ ;
  mp[L]++ ;
  mp[O]++ ;
  if( mp[1]==1 && mp[9]==1 && mp[7]==1 && mp[4]==1) cout <<  "YES" << endl;
  else cout << "NO" << endl;
}