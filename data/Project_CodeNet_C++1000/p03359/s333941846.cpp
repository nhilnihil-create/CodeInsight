#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<utility>//swapでaとbの値を入れ替える
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
#define s(s) sort(s.begin(),s.end())
#define r(s) reverse(s.begin(),s.end())
using namespace std;
int main() {
	int a,b,ans;
	cin >> a>>b;
	if (a > b)ans = a - 1;
	else ans = a;
	cout << ans << endl;

	return 0;
}
	

