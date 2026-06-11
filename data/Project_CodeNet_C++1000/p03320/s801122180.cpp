// Comment
// xx99999999

#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
using ll = long long;
using pi = pair<int, int>;
const int INF = 0x3f3f3f3f;
const ll LINF = 1ll * INF * INF;

int S(ll v) {
	int res=0;
	while(v) res+=v%10, v/=10;
	return res;
}

ll F(ll v) {
	ll a = LINF / 1000, b = 1;

	int len = 0;
	ll temp = v;
	while(temp) len++, temp /= 10;

	ll p = 1;
	temp = v;
	for(int i=0; i<len; i++) {
		temp = temp / (p * 10) * (p * 10);
		temp += p - 1;
		for(int j=0; j<10; j++) {
			if (j != 0) temp += p;
			if (v > temp) continue;
			if (a * S(temp) > temp * b) {
				a = temp;
				b = S(temp);
			}
		}
		p *= 10;
	}
	return a;
}

int K;
int main() {
	cin >> K;
	ll now = 0;
	for(int i=1; i<=K; i++) {
		if(i == 1) now = 1;
		else{
			now = F(now+1);
		}
		printf("%lld\n", now);
	}
	return 0;
}

