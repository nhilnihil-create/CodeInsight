#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <functional>
#include <queue>

using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<(int)n;++i)

int X,Y,Z,K;

struct Data {
	int v, a, b, c;
	Data(int v, int a, int b, int c) : v(v), a(a), b(b), c(c) {}
	bool operator<(const Data &data) const {
		return v < data.v;
	}
	bool operator>(const Data &data) const {
		return v > data.v;
	}
};

map<int, bool> used;

int encode(int a, int b, int c)
{
	return a + b*1000ll + c*1000ll*1000ll;
}

signed main()
{
	cin >> X >> Y >> Z >> K;

	vector<int> A(X), B(Y), C(Z);
	rep(i, X) cin >> A[i];
	rep(i, Y) cin >> B[i];
	rep(i, Z) cin >> C[i];

	sort(begin(A), end(A), greater<int>());
	sort(begin(B), end(B), greater<int>());
	sort(begin(C), end(C), greater<int>());

	priority_queue<Data> pq;
	pq.push(Data(A[0]+B[0]+C[0],0,0,0));

	rep(_, K) {
		Data d(0,0,0,0);
		int v,a,b,c;

		do {
			d = pq.top();
			v = d.v, a = d.a, b = d.b, c = d.c;
			pq.pop();
		} while (used[encode(a,b,c)]);

		used[encode(a,b,c)] = true;

		cout << v << endl;

		if (a + 1 < X) pq.push(Data(A[a+1]+B[b]+C[c], a+1,b,c));
		if (b + 1 < Y) pq.push(Data(A[a]+B[b+1]+C[c], a,b+1,c));
		if (c + 1 < Z) pq.push(Data(A[a]+B[b]+C[c+1], a,b,c+1));
	}
}
