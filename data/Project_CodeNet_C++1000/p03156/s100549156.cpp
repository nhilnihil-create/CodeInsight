#include <bits/stdc++.h>
using namespace std;

int cnt[3];

int main() {
	int n, a, b; cin >> n >> a >> b;
  	for (int i=0;i<n;i++) {
    	int x; cin >> x;
      	if (x<=a) cnt[0]++; else if (x<=b) cnt[1]++; else cnt[2]++;
    }
  	cout << min(cnt[0], min(cnt[1], cnt[2])) << endl;
}