#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <stack> // s.top()
#include <bitset>
#include <queue> // s.front()
using namespace std;

typedef long long Int;
typedef pair<Int,Int> P;
#define print(x) cout<<(x)<<endl

#define INF10 10000000000
#define INF5 100000
#define EPS 1e-10
#define MOD 1000000007



int main() {
	int A, B, K; cin >> A >> B >> K;
	for (int _ = 0; _ < K; _++) {
		if (_ % 2 == 0) {
			if (A % 2 == 1)A--;
			A /= 2;
			B += A;
		}
		else {
			if (B % 2 == 1)B--;
			B /= 2;
			A += B;
		}

	}
	cout << A << " " << B << endl;




	



	return 0;
}