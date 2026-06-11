#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int a,b;
	cin >> a >> b;
	int c = b-a;
	int ans = (1+c)*c/2 - b;
	cout << ans << endl;
}