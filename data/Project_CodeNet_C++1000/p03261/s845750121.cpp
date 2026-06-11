#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<string> w(n);
  string first;
  cin >> first;
  w[0] = first;
  string word;
  for(int i = 1; i < n; i++){
  	cin >> w.at(i);
    if(w[i-1][w[i-1].length()-1] != w[i][0]){
    	cout << "No" << endl;
      	return 0;
    }
    int cnt = 0;
    for(int j = 0; j < w.size(); j++){
      	if(w[i] == w[j]) cnt++;
      	if(cnt == 2){
        	cout << "No" << endl;
          	return 0;
        }
    }
  }
  cout << "Yes" << endl;
  return 0;
}