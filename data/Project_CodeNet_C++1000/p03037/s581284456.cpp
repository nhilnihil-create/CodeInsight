#include <bits/stdc++.h>
#define MOD (long long)(1E9+7)
#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
  	vector<int> l(m);
  	vector<int> r(m);
  	rep(i, m)
      	cin >> l[i] >> r[i];
  	cout << max(0, *min_element(r.begin(), r.end()) - *max_element(l.begin(), l.end()) + 1) << endl;
}
