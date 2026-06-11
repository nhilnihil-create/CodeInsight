#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
// const ll INF = 1000000000000000000LL;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	int l=0;
	rep(i,n){
		cin >> a[i];
		if(a[i]%2==0) l++;
	}
	cout << pow(3,n)-pow(2,l) << endl;
	return 0;
}

