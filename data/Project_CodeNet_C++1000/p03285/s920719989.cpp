#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  int cake = n/4, don = n/7;
  rep(i, cake+1){
  	rep(j, don+1){
    	if((i*4 + j*7) == n){
        	cout << "Yes" << endl;
          	return 0;
        }
    }
  }
  cout << "No" << endl;
  return 0;
}