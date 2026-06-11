#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	string s;
	cin >> n >> s;
	vector<int> l(n);
	vector<int> r(n);
	l.at(0) = 0;
	r.at(0) = 0;
	rep(i, n){
		if(i != 0){
			l.at(i) = l.at(i-1);
			r.at(i) = r.at(i-1);
		}
		if(s.at(i) == 'W'){
			l.at(i)++;
		}else{
			r.at(i)++;
		}
	}
	int mi = min(l.at(n-2), r.at(n-1) - r.at(0));
//	cout << l.at(n-2) << ' ' << r.at(n-1) - r.at(0) << endl;
	for(int i=1; i<n-1; i++){
		int sum = l.at(i-1) + r.at(n-1) - r.at(i);
//		cout << l.at(i-1) << ' ' << r.at(n-1) - r.at(i) << endl;
		if(sum < mi) mi = sum;
	}
	cout << mi << endl;
	return 0;
}
