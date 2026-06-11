#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m, c;
  cin >> n >> m >> c;
  vector<int> b(m);
  rep(i, m){
	cin >> b.at(i);  	
  }
  int cnt = 0;
  rep(i, n){
    int sum = 0;
  	rep(j, m){
    	int num; cin >> num;
      	sum += b[j] * num;
    }
    if(sum + c > 0){
    	cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}