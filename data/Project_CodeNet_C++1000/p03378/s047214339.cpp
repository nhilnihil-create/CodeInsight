#include <bits/stdc++.h>
using namespace std;

int main() {
  int n , m ,x;
  cin >> n >> m >> x;
  vector <int> a(m);
  for (int i=0 ; i<m ; i++){
    cin >> a.at(i) ;
  }
  int cost_s=0 , cost_g=0 ;
   for (int i=0 ; i<m ; i++){
    if (a.at(i)<x){
      cost_s ++ ;
    }else if ( a.at(i)>x){
      cost_g ++ ;
    }
   }
  cout << min ( cost_s,cost_g) << endl; 
}