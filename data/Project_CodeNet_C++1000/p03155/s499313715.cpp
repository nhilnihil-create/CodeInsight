#include <bits/stdc++.h>
using namespace std;

int main(){
 	int n, ans, x, y;
  	cin >> n;
  	cin >> x >> y;
  	ans = (n - x + 1) * (n - y + 1);
  	cout << ans;
}