#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	vector<int> l(n);
	int ml = 0;
	int mn = 11;
	rep(i,n){
		cin >> l[i];
		if(l[i] > ml){
			ml = l[i];
			mn = i;
		}
	}
	int sum = 0;
	rep(i,n){
		if(i == mn) continue;
		sum += l[i];
	}
	if(sum > ml) cout << "Yes" << endl;
	else cout << "No" << endl;
}