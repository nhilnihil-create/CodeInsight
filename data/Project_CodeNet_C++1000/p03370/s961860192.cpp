#include <bits/stdc++.h>
	
using namespace std;
inline void FAST_IO(){ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);}

template<class F, class S> ostream& operator<<(ostream& os, pair<F, S> &p) {
	os << "(" << p.first << "," << p.second << ")";
	return os;
}

template<class T, class S> ostream& operator<<(ostream& os, map<T, S> &v) {
	os << "{";
	for(auto &i : v) cout << "{" << i.first << "," << i.second << "}";
	os << "}";
	return os;
}

template<class T> ostream& operator<<(ostream& os, set<T> &v) {
	os << "{";
	for(auto &i : v) cout << i << ",";
	os << "}";
	return os;
}
 
template<class T> ostream& operator<<(ostream& os, vector<T> &v) {
	os << "[";
	if(v.size()) os << v[0];
	for(int i = 1; i < v.size(); ++i) os << "," << v[i];
	os << "]";
	return os;
}

/*----------------------------------------------------------------------------*/

int main (){
	// FAST_IO();

	int n,x;
	cin >> n >> x;

	priority_queue<int> pq;
	int resp = 0;

	while(n-->0) {
		int in;
		cin >> in;
		pq.push(-in);
		if (x >= in)  {
			x -= in;
			resp++;
		}
	}

	while(x > 0 && !pq.empty()) {
		int v = -pq.top();
		if (x >= v) {
			resp += x/v;
			x -= (x/v)*v;
		}
		pq.pop();
	}

	cout << resp << endl;

	return 0;
}
