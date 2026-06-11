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
#define rep(i,a,b) for((i)=a;i<(int)(b);i++)
#define Max(a,b) ((a) < (b) ? (b) : (a))
#define Min(a,b) ((a) > (b) ? (b) : (a))
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


int main() {
	int i, j, k;
	int N, M, K;

	cin >> N;
	int A[100];
	int B[100];
	rep(i, 0, N) {
		cin >> A[i];
		A[i]--;
		B[i] = i - A[i];
	}
	stack<int> Ans;
	rep(i, 0, N) {

		int a=-1;
		rep(j, 0, N) {
			if (A[j] == -1) continue;
			if (B[j] == 0)
				a = j;
		}
		if (a == -1) {
			cout << "-1";
			return 0;
		}
		Ans.push(A[a]);
		A[a] = -1;
		rep(j, a + 1, N) {
			B[j] --;
		}

	}
	rep(i,0,N){
		int a = Ans.top();
		Ans.pop();
		cout << a+1 << endl;
	}
	return 0;

}


