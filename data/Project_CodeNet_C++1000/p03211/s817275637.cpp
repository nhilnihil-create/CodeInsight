#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  
  int min = 1000;
  int n = 753;
  
  int h=0;
  int t=0;
  int o=0;
  
  for(int i=0; i < s.size()-2; i++){
    
    h=100 * (s.at(i)-'0');
    t=10 * (s.at(i+1)-'0');
    o=1 * (s.at(i+2)-'0');
      
    if(h+t+o >= n){
      if(h+t+o - n <= min){
      min = h+t+o - n;
      }
    }
    
    else{
      if(n - (h+t+o) <= min){
      min = n - (h+t+o);
      }
    }
    
  }
  
  cout << min << endl;
  
	return 0;
}
