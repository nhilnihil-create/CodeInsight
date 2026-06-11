#include <bits/stdc++.h>
using namespace std;

int main() {
  int n ;
  cin >> n ;
  vector <int> a(n) ;
  vector <int> count(n,0) ;
  for (int i=0 ; i<n ; i++){
    cin >> a.at(i) ;
  }
  for (int i = 0 ; i<n ; i++){
  for ( int j=a.at(i) ; j%2==0 ; j/=2){
    count.at(i) ++ ;
  }
  }
  sort(count.begin() , count.end());
  cout << count.at(0) << endl;
}