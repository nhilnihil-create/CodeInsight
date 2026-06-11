#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	vector<int> p(n);
	int mp = 0;
	int mn = 11;
	rep(i,n){
		cin >> p[i];
		if(mp < p[i]){
			mp = p[i];
			mn = i;
		}
	}
	int sum = 0;
	rep(i,n){
		if(i == mn) sum += p[i]/2;
		else sum += p[i];
	}
	cout << sum << endl;
}