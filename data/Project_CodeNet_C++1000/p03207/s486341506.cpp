#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> price(n);
	for(int i=0; i<n; i++){
      cin >> price.at(i) ;
    }
  sort(price.begin(),price.end());
  price.at(n-1) /= 2;
    
    int pay=0;
   for(int i=0; i<n ; i++){
     pay += price.at(i);
   }
  cout << pay;
}