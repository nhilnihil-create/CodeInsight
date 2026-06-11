#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
set<pair<int,int> > st;
int n, x[N], mx;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> x[i];
		mx = max(mx, x[i]);
	}
	for (int i = 0; i < n; i++)
		if(x[i] != mx)
			st.insert({abs(mx / 2 - x[i]), i});
		
	cout << mx << ' ' << x[(*st.begin()).second];
}
