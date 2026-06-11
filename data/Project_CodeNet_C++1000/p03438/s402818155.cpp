#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define repitr(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	rep(snip_i, n) cin >> a.at(snip_i);
	vector<int> b(n);
	rep(snip_i, n) cin >> b.at(snip_i);
	rep(i, n){
		if(a.at(i) <= b.at(i)) continue;
		else{
			int dif = a.at(i) - b.at(i);
			rep(j, n){
				if(a.at(j) < b.at(j)){
					int temp = b.at(j) - a.at(j);
					if(temp >= 2 * dif){
						a.at(j) += 2 * dif;
						b.at(i) += dif;
						dif = 0;
					}else{
						a.at(j) += temp/2*2;
						b.at(i) += temp/2;
						dif -= temp/2;
					}
				}
				if(dif <= 0) break;
				else if(j == n-1){
					cout << "No" << endl;
					return 0;
				}
			}
		}
	}

	// rep(i, n){
	// 	if(i != 0) cerr << " ";
	// 	cerr << a.at(i);
	// }
	// cerr << endl;
	// rep(i, n){
	// 	if(i != 0) cerr << " ";
	// 	cerr << b.at(i);
	// }
	// cerr << endl;

	if(a.at(n-1) <= b.at(n-1)){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0;
}