#include <bits/stdc++.h>
using namespace std;

int a[110];
multiset<int> s;

int main() {
	ios_base::sync_with_stdio(0);
  	int n, m; cin >> n;
  	for (int i=0;i<n;i++) {
    	int x; cin >> x;
      	s.insert(x);
    }
  	cin >> m;
  	for (int i=0;i<m;i++) {
    	int x; cin >> x;
      	auto t = s.find(x);
      	if (t==s.end()||*t!=x) {
        	cout << "NO\n";
            return 0;
        }
      	s.erase(t);
    }
  	cout << "YES\n";
}