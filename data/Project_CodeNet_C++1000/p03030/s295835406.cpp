#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<tuple<string, int, int>> p(N);
  
  for (int i = 0; i < N; i++) {
    string a;
    int b;
    cin >> a >> b;
    get<0>(p.at(i)) = a;
    get<1>(p.at(i)) = -b;
    get<2>(p.at(i)) = i + 1;
  }
  
  sort(p.begin(), p.end());  
  
  for (int i = 0; i < N; i++) {
    
  	cout << get<2>(p.at(i)) << endl; 
  }
  
}