#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n, m) for (int i = n; i >= m; i--)

int main(){
	string s, t;
	cin >> s >> t;
	sort(s.begin(), s.end());
	sort(t.begin(), t.end(), greater<>());

	if(s < t){
		cout << "Yes\n";
	}else{
		cout << "No\n";
	}
}
