#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <numeric>
#include <queue>
#include <numeric>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <map>
#include <functional>
#include <limits>
#include <set>
#include <stack>
#include <cctype>
#define rep(i,a,b) for((i)=a;i<(int)(b);i++)

#define AAA (1000000007) 


using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pairII;


ll gcd(ll a, ll b) {
	if (b == 0)return a;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}
ll powD(ll a, ll b) {
	ll ans = 1;
	a %= AAA;
	for (int i = 0; i < b; i++)
	{
		ans *= a;
		ans %= AAA;
	}
	return ans;
}

int primeNumber(const int n) {
	//上から確認する
	for (int N = n; N >= 1; N--) {

		bool isPrime = true;
		//素数判定 i < sqrt(N)+1
		for (int i = 2; i * i <= N; i++) {
			if (N % i == 0) {
				isPrime = false;
				break;
			}
		}
		//もし素数なら
		if (isPrime) {
			return N;
		}
	}
}


int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	vector<int> B(N);
	ll Sa = 0, Sb = 0;
	int i;
	rep(i, 0, N) {
		cin >> A[i];
		Sa += A[i];
	}
	rep(i, 0, N) {
		cin >> B[i];
		Sb += B[i];
	}

	ll a, b;
	a = b = 0;
	rep(i, 0, N) {
		if (A[i] >= B[i]) {
			b += A[i] - B[i];
		}
		else {
			a += (B[i] - A[i]) / 2;
			if ((B[i] - A[i]) % 2 == 1) {
				b++;
				a++;
			}
		}
	}
	//cout << a << " " << b;
	if (a - b >= 0)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}
