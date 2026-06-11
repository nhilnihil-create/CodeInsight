#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
typedef pair<int,int> pi;
#define FAST ios_base::sync_with_stdio(0);
const int maxn = 100010;
 
string S;
int main() {
	cin >> S;
	int n = S.length();
	int ans1 =n,ans2 = n;
	S = '0' + S;
	for (int i =1;i<=n;i++) {
		int res;
		res = max(max(i-1,n-i), min(i,n-i+1));
		if (S[i] == '1') {
			//~ cout << i << " " << res << "\n";
			ans1 = min(ans1,res);
		} else {
			ans2 = min(ans2,res);
		}
	}
	cout << max(ans1,ans2);
}
