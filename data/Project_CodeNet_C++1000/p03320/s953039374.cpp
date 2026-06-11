#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;

double calc(ll x) {
	ll tmp = x, sum = 0;
	while(x) {
		sum += x % 10;
		x /= 10;
	}
	return 1.0 * tmp / sum;
}

int main()
{
	int k;
	cin>>k;
	ll x = 1, tmp = 0;
	while(k--) {
		double s1, s2;
		while(1) {
			s1 = calc(tmp + x), s2 = calc(tmp + x * 10);
			if(s1 <= s2) break;
			x *= 10;
		}
		tmp += x;
		cout<<tmp<<endl;
	}
	return 0;
}