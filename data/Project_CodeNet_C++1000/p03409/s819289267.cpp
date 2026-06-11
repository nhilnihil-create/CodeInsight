#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i < n; ++i)
typedef pair<int,int> P;
const int INF=1e9+7;

int main() {
	int N,a=0;
	cin >> N;
	vector<P> r(N),b(N);

	rep(i,N)
		cin >> r.at(i).first >> r.at(i).second;
	rep(i,N)
		cin >> b.at(i).first >> b.at(i).second;
	sort(b.begin(), b.end());

	rep(i,N) {
		int mi=-1,my=-1;
		rep(j,N)
			if(r.at(j).first<b.at(i).first && r.at(j).second<b.at(i).second && r.at(j).second > my)
				mi=j, my=r.at(j).second;
		if(mi != -1) {
			++a;
			r.at(mi).first=INF, r.at(mi).second=INF;
		}
	}

	cout << a << endl;
}