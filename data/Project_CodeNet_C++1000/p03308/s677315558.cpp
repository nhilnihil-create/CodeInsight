#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
  	int max = 1;
  	int min = 1000000000;
  	cin >> n;
  	vector<int> a(n);
  for(int i = 0; i < n; i++){
      cin >> a.at(i);
  }
  for(int i = 0;i < n; i++){
    if(max < a.at(i)) max = a.at(i);
    if(min > a.at(i)) min = a.at(i);
  }
  cout << max - min <<endl;
}