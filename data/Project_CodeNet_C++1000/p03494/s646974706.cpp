#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector <int> a(N);
  vector <int> count(N, 0) ;
  int mx = 100 ;
  for ( int i=0 ;i< N ; i++){
    cin >> a.at(i) ;
    for ( int j = a.at(i) ; j%2 == 0 ; j/=2){
      count.at(i) ++ ;
    }
    mx = min ( mx , count.at(i)) ;
  }
  cout << mx << endl;
}