#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,a,b,c;
  cin >> A >> a;

  vector<int> vec(100010,0);

	for(int i=0;i<a;i++){
		// cout << 34343 << endl;
		cin >> b >> c;
		vec.at(b-1) += 1;
		vec.at(c) -=1;
	}
	int ans = 0;
	int tmp =0;

	for(int i=0;i<100002;i++){
		tmp += vec.at(i);
		// cout << vec.at(i) << endl;
		if (tmp == a)ans +=1;
	}
	cout << ans << endl;
}
