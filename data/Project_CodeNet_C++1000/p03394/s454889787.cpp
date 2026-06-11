#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	if(n == 3){
		cout << "2 5 63" << endl;
		return 0;
	}
	
	if(n == 4){
		cout << "2 3 4 9" << endl;
		return 0;
	}

	if(n == 5){
		cout << "2 3 4 6 9" << endl;
		return 0;
	}

	multiset<ll> ms;
	ll sm = 0;
	ll t = 0;

	// 2 3 4 6 / 8 9 10 12 / ...
	for(int i = 0; i < n; i++){
		if(i % 4 == 0) t += 2;
		else if(i % 4 == 1) t += 1;
		else if(i % 4 == 2) t += 1;
		else if(i % 4 == 3) t += 2;
		ms.insert(t);
		sm += t;
	}

	if(sm % 6 == 2){
		ms.erase(8);
		ms.insert(30000);
	}else if(sm % 6 == 3){
		ms.erase(9);
		ms.insert(30000);
	}else if(sm % 6 == 5){
		ms.erase(9);
		ms.insert(29998);
	}

	for(ll x : ms){
		cout << x << " ";
	}
	cout << endl;
}
