#include <bits/stdc++.h>
using namespace std;
using ll=long long;


int main() {
  int n , h , w ;
  cin >> n >> h >> w ;
  
  vector<int> a(n);
  vector<int> b(n);
  int c =0;
  for(int i=0; i<n ; i++ ){
    cin >> a.at(i);
    cin >> b.at(i);
  if(a.at(i)>=h&&b.at(i)>=w){
    c++;
  }
  }
  
  cout << c << endl;
}