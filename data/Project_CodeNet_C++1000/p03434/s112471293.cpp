#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N ; 
  vector <int> c(N);
  for ( int i=0 ; i<N ; i++ ){
    cin >>c.at(i) ;
  }
  sort (c.begin() , c.end());
  int sum=0;
  for (int i=0 ; i<N ; i++){
    sum +=c.at(N-i-1)*( i%2==0 ? 1:-1);
  }
    cout << sum << endl;
}