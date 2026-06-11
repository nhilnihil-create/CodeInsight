#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;

int main() {
	ll K,A,B;
	cin >> K >> A >> B;
	cout << max(K+1, max(0ll,(K+1-A)/2)*(B-A)+((K>A-2)?A:0)+(((K+1-A)/2>0)?((K+1-A)%2):0)) << endl;
}