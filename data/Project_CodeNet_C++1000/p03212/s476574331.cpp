#include<bits/stdc++.h>
using ll = long long;
using namespace std;
/*........................................DEFINE FUNCTIONS.........................................*/
int N;
int ans;
/*....................................DEFINE GLOBAL VARIABLES .....................................*/
void func(ll cur, int use) {
	if (cur > N)return;
	if (use == 0b111)ans++;
	func(cur * 10 + 3, use | 0b001);
	func(cur * 10 + 5, use | 0b010);
	func(cur * 10 + 7, use | 0b100);
}
/*.........................................kemkemG0................................................*/
int main() {
	cin >> N;
	func(0, 0);
	cout << ans << endl;
	return 0;
}