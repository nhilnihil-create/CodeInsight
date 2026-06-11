#include <bits/stdc++.h>
#define int long long 
using namespace std;
using Graph = vector<vector<int>>;

signed main(){
  int N;
  cin >> N;
  
  vector<tuple<int, int, int>> A(N);
  for( int i = 0; i < N; i++ ){
    int a, b;
    cin >> a >> b;
    A.at(i) = make_tuple(a+b, a, b);
  }
  sort(A.rbegin(), A.rend());
  
  int taka = 0;
  int aoki = 0;
  for( int i = 0; i < N; i++ ){
    if( i%2 == 0 ){
      taka += get<1>(A.at(i));
    }else{
      aoki += get<2>(A.at(i));
    }
  }
  cout << taka-aoki << endl;
  
}
