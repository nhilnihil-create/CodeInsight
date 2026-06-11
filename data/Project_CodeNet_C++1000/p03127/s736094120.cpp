#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<int> A;
	int mina = 1e9+5;
	rep(i,N){ 
		int a;
		cin >> a;
		if (a < mina) mina = a; 
		A.push_back(a);
	}

	while (A.size() > 1) {
		vector<int> v;
		int tmp = mina;
		for (int a : A) {
			a %= mina;
			if (a > 0) {
				tmp = min(tmp, a);
				v.push_back(a);
			}
		}
		v.push_back(mina);
		mina = tmp;
		A = v;
	}

	cout << mina << endl;

	return 0;
}
