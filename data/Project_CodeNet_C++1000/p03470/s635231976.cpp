#include<bits/stdc++.h>
using namespace std;

#define deb(x) cerr<<"["#x<<" : "<<x<<" ]\n";

int main()
{
	int n;
	cin >> n;
	unordered_set<int> s;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		s.insert(x);
	}
	cout << (int)s.size();
}
