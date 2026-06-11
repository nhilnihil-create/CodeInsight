#include <bits/stdc++.h>
using namespace std;



int main(){
    int n, m;
	cin >> n >> m;
	int a[m];
	for(int i=0; i<m; i++)
		cin >> a[i];
	if(n>=m)
		cout << 0 << endl;
	else{
		sort(a, a+m);
		vector<int> res;
		for(int i=1; i<m; i++)
			res.push_back(a[i]-a[i-1]);
		sort(res.begin(), res.end());
		int ans = 0;
		for(int i=0; i<m-n; i++)
			ans += res[i];
		cout << ans << endl;
	}
}