#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int n,m;
  cin >> n >> m;
  
  vector<pair<int,int>> p;
  long long a,b;
  
  
  for ( int i = 0; i < n; i++){
    cin >> a >> b;
    p.push_back(make_pair(a,b));
  }
  
  sort(p.begin(),p.end());
  
  long long cnt = 0,price = 0;
  
  for ( int i = 0; i < n; i++){
    tie(a,b) = p[i];
    //cout << a << ' ' << b << endl;
    if ( cnt + b <= m ){
      cnt += b;
      price += a * b;
    }else{
      price += a * ( m - cnt );
      break;
    }
    //cout << cnt << ' ' << price << endl;
  }
  
  cout << price << endl;  
 
}
