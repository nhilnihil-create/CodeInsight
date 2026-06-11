#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
  string s;
  cin >> s;
  int front, back;
  front = stoi(s.substr(0, 2));
  back = stoi(s.substr(2, 2));
  
  if(front >= 1 && front <= 12) {
    if(back >= 1 && back <= 12) {
    	cout << "AMBIGUOUS" << endl;
      	return 0;
    }else {
    	cout << "MMYY" << endl;
      	return 0;
    }
  }else {
  	if(back >= 1 && back <= 12) {
    	cout << "YYMM" << endl;
      	return 0;
    }
  }
  cout << "NA" << endl;
  return 0;
}
