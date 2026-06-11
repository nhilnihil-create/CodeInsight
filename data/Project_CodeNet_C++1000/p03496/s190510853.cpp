#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> pi;
#define f first
#define s second
#define FAST ios_base::sync_with_stdio(0); cin.tie(0);

int n;
int main() {
	FAST
	cin >> n;
	vector <int> a(n);
	vector <pi> ans;
	for (int i =0;i<n;i++) cin >> a[i];
	auto maxn = max_element(a.begin(),a.end());
	auto minn = min_element(a.begin(),a.end());	
	int maxp = maxn - a.begin() + 1, minp = minn - a.begin() + 1;
	
	if (abs(*maxn) >= abs(*minn)) {
		for (int i =1;i<=n;i++) ans.push_back(pi(maxp,i));
		for (int i =2;i<=n;i++) ans.push_back(pi(i-1,i));
		
	} else if (abs(*maxn) < abs(*minn)) {
		for (int i = 1;i<=n;i++) ans.push_back(pi(minp,i));
		for (int i =n-1;i >= 1; i--) ans.push_back(pi(i+1,i));
	}
	cout << ans.size() << "\n";
	for (auto cur: ans) cout << cur.f << " "<< cur.s << "\n";
	
}	

