#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  int N, A, B;
  cin >> N >> A >> B;
  
  int P;
  int one = 0;
  int two = 0;
  int san = 0;
  for( int i = 0; i < N; i++ ){
    cin >> P;
    if( P <= A ) one++;
    else if( P <= B ) two++;
    else san++;
  }
  
  cout << min({one, two, san}) << endl;
    
}