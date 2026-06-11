#include <bits/stdc++.h>
#define int long long
using namespace std;

int gcd(int a, int b){
	if(!a) return b;
	return gcd(b%a,a);
}

int lcm(int x, int y){
	if(x == 0 || y==0) return 0;
	return x/gcd(x, y) *y;
}

signed main() {
  int N, M;
  cin >> N >> M;
  string S, T;
  cin >> S >> T;
  
  int L = lcm(N, M);
  
  map<int, char> koyaku;
  for( int i = 0; i < N; i++ ){
    koyaku[i*(L/N)] = S.at(i);
  }
  
  for( int i = 0; i < M; i++ ){
    if( koyaku.count(i*(L/M)) ){
      if( koyaku.at(i*(L/M)) != T.at(i) ){
        cout << -1 << endl;
        return 0;
      }
    }
  }
  
  cout << L << endl;
    
  
  
}
