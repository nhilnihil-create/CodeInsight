#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n, c, in;
	cin >> n >> c;
	vector<vector<int>> cc(c, vector<int>(c));
	vector<vector<int>> gr(3, vector<int>(0));
	rep(i, c) rep(j, c){//900
		cin >> in;
		cc.at(i).at(j) = in;
	}
	rep(i, n) rep(j, n){//250000
		cin >> in;
		in--;
		gr.at((i+j)%3).push_back(in);
	}
	ll mi = 25000000000;
	vector<vector<int>> cos(3, vector<int>(c));
	rep(k, 3){
		rep(i, c){
			ll sum = 0;
			rep(jj, gr.at(k).size()){//250000
				sum += cc.at(gr.at(k).at(jj)).at(i);
			}
			cos.at(k).at(i) = sum;
		}
	}
	rep(i, c) rep(j, c) rep(l, c){//27000
		if(i == j || j == l || l == i) continue;
		ll sum = 0;
		sum += cos.at(0).at(i);
		sum += cos.at(1).at(j);
		sum += cos.at(2).at(l);
		if(sum < mi) mi = sum;
	}
	cout << mi << endl;
	return 0;
}
