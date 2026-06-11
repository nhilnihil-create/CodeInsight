#include <bits/stdc++.h>
	
using namespace std;
inline void FAST_IO(){ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);}

template<class F, class S> ostream& operator<<(ostream& os, pair<F, S> &p) {
	os << "(" << p.first << "," << p.second << ")";
	return os;
}
 
template<class T> ostream& operator<<(ostream& os, set<T> &v) {
	os << "(";
	for(auto &i : v) cout << i << ",";
	os << ")";
	return os;
}
 
template<class T> ostream& operator<<(ostream& os, vector<T> &v) {
	os << "(";
	if(v.size()) os << v[0];
	for(int i = 1; i < v.size(); ++i) os << "," << v[i];
	os << ")";
	return os;
}

/*----------------------------------------------------------------------------*/

int main (){
	// FAST_IO();

	int n;
	cin >> n;

	cout << n/3 << endl;

	return 0;
}