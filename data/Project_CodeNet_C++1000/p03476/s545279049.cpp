#include<bits/stdc++.h>
using namespace std;

bool IsPrime(long long n){
    if(n < 2) return false;
    else if(n == 2) return true;
    else if(n % 2 == 0) return false;
    for(long long i = 3; i * i <= n; i += 2){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int main()
{
	int q;
	cin >> q;
	vector<int> a(100001);
	for(int i = 1; i < 100001; i++){
		if(IsPrime(i) && IsPrime((i + 1) / 2) && i % 2) a[i] = 1;
		a[i] += a[i - 1];
	}
	for(int i = 0; i < q; i++){
		int l, r;
		cin >> l >> r;
		cout << a[r] - a[l - 1] << endl;
	}
	return 0;
}