#include <bits/stdc++.h>
using namespace std;


#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

#define MAXX 100005
#define INF INT_MAX

#define PI   3.14159265358979323846264338327950

#define PB push_back
#define PF push_front
#define F first
#define S second

#define fixx(n) fixed << setprecision(n)

#define ll 	 long long 

#define mod  1000000007



int main()
{
	FAST;
	string s;
	cin >> s;
	int n = s.size();
	int ans = 800;
	for(int i = 0; i < n - 2; i ++){
		int m = 0;
		for(int j = i; j < i + 3; j ++){
			m = m*10 + (s[j] - 48);
		}
		ans = min(abs(753 - m), ans);
	}
	cout << ans;
	return 0;
	
}