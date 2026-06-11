#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	int Alice = 0;
	int Bob = 0;
	rep(i,n){
		if(i%2 == 0) Alice += a[i];
		else Bob += a[i];
	}
	cout << Alice - Bob << endl;
}