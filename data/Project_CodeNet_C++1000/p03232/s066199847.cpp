#include <iostream>
using namespace std;
long long mod = 1e9+7,fact[200000],inv[200000],result[200000],cd,a[200000];
long long bigmod(long long base , long long hat)
{
		if (hat == 0) return 1;
		long long k = bigmod(base , hat / 2);
		if (hat % 2 == 0) return k * k % mod;
		return k * k % mod * base % mod;
}
long long C(long long k , long long n)
{
		if (k > n) return 0;
		return fact[n] * inv[n-k] % mod * inv[k] % mod;
}
void prepare()
{
		for (long long i = 0 ; i <= 100000 ; i++)
		{
				if (i == 0) fact[i] = 1;
				else        fact[i] = fact[i-1] * i % mod;
				inv[i]  = bigmod(fact[i] , mod - 2);
		}
}
void dp()
{
		for (long long i = 1 ; i <= 100000 ; i++)
		{
				result[i] = (result[i-1] + fact[i-1] + result[i-1] * (i-1)) % mod;
				//if (i <=4) cout <<"result["<<i<<"] : "<<result[i]<<endl;
		}
}
long long get()
{
		long long kq = 0;
		for (long long i = 1 ; i <= cd ; i++)
		{
			//	kq += C(i , cd) * result[i] % mod * (result[cd-i+1] - fact[cd-i+1] + mod) % mod * a[i] % mod;
				kq += C(i , cd) * result[i] % mod * a[i] % mod * fact[cd-i] % mod;
				kq += C(cd - i + 1 , cd) * (-fact[cd-i+1] + mod + result[cd - i + 1]) % mod * a[i] % mod * fact[cd - (cd - i + 1)] % mod;
				kq %= mod;
			//	cout <<"kq : "<<kq<<endl;
		}
		return kq;
}
int main()
{
		prepare();
		cin >> cd;
		for (int i = 1 ; i <= cd ; i++)
		{
				cin >> a[i];
		}
		dp();
		cout <<get();
}