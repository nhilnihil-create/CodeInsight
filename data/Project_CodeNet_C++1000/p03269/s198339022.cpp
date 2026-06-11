#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF INT_MAX
#define LLINF LLONG_MAX
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec) {
    for (T& x: vec) { is >> x; }
    return is;
}

int main() {
	ll ans = 0;
	ll tmp;
	int l; 
	cin >> l;
	int m = 0;
	vector<tuple<int, int, int>> v;
	for(int i= 2; i<= 19; i++){
		v.push_back(make_tuple(i, i+1, 0));
		v.push_back(make_tuple(i, i+1, 1<<(19-i)));
		m+=2;
	}
	int mi = 0; 
	for(int sh = 0; mi<l; sh++){
		if(l &(1<< sh)){
			v.push_back(make_tuple(1, 20-min(sh,18), mi));
			mi+=(1<<min(sh,18));
			m++;
		}
	}
	cout << "20 " << v.size() << endl;
	REP(i, v.size()){
		cout << get<0>(v[i]) << " " << get<1>(v[i]) << " " << get<2>(v[i]);
		cout << endl;
	}
    return 0;
}