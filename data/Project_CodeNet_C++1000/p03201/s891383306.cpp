#include<bits/stdc++.h>
using namespace std;

#define ll long long
int n, x, ans=0;
multiset<int> s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> x;
		s.insert(x);
	}	

	for(int i=0;i<n && s.size();i++) {
		int e = *(--s.end());
		s.erase(--s.end());
		for(int j=0;j<32;j++) {
			if(s.find((1<<j) - e) != s.end()) {
				ans++;
				s.erase(s.find((1<<j) - e));
				break;
			}
		}
	}
	cout << ans;
}