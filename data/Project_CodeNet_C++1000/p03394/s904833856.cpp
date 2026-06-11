#include <bits/stdc++.h>
using namespace std;

#define int long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

signed main(){
	int n;
	cin >> n;


	vector<int> a(n);

	if(n == 3){
		cout << 2 << " " << 3 << " " << 25 << endl;
		return 0;
	}

	int ans = 2+3;
	a[0] = 2;
	a[1] = 3;
	int used[30010] = {};
	used[2] = used[3] = 1;
	int i = 4;
	for(int ii = 2;ii < n-1;ii++){
		while(1){
			if(used[i] == 0 && (i % 2 == 0 || i % 3 == 0)) break;
			i++;
		}
		a[ii] = i;
		ans += a[ii];
		used[a[ii]]++;
	}

	int atmp[30010] = {};
	int go = 0;
	for(int i = 0;i < n-1;i++){
		bool f = false;
		for(int j = 2;j*j <= a[i];j++){
			if(a[i] % j == 0){
				f = true;
				break;
			}
		}
		if(f) continue;
		go++;
		int tmp = ans-a[i];
		for(int j = 0;j <= 30000;j++){
			if(__gcd(tmp+j, a[i]) != 1 && __gcd(ans, j) != 1) atmp[j]++;
		}
	}

	for(int i = 2;i <= 30000;i++){
		if(used[i] == 0 && atmp[i] == go){
			for(int i = 0;i < n-1;i++){
				cout << a[i] << " ";
			}
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}
