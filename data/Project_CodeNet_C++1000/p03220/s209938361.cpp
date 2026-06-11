#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;

int main(){
	int n, t, a, h;
	cin >> n >> t >> a;
	int tmp = 0;
	int cc = 999999;
	for(int i = 1; i <= n; i++){
		cin >> h;
		int d = (t * 1000 - h * 6) - a * 1000;
		if(cc > abs(d)) cc = abs(d), tmp = i;
	}
	cout << tmp << endl;

    return 0;
}