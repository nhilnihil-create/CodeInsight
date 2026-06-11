#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 210;
typedef long long ll;
int n;	
char s[N];
bool vis[N];
int main() {
	
	cin >> n;
	scanf("%s", s + 1);
	int ans = 0;
	for(int i = 1; i < n; i++) {
		for(int j = 1; j <= i; j++) {
			vis[s[j]] = 1;
		}
		int tmp = 0;
		for(int j = i + 1; j <= n; j++) {
			if(vis[s[j]]) tmp++, vis[s[j]] = 0;
		}
		ans = max(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}