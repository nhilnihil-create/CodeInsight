#include<bits/stdc++.h>
using namespace std;

vector<bool> f() {
	vector<bool> ok(55555, true);
	ok[0] = false; ok[1] = false;
	for (int i = 2; i * i < 55555; i++)
	{
		if(!ok[i]) continue;
		for (int j = i * i; j < 55555; j+=i)
		{
			ok[j] = false;
		}
	}
	return ok;
}

int main() {
    int n; cin >> n;
	vector<bool> prime = f();
	int res = 0;
	int i = 11;
	while (res < n)
	{
		if(prime[i] && i % 5 == 1) {
			cout << i << " ";
			res++;
		}
		i++;
	}
	cout << endl;
	return 0;
}
