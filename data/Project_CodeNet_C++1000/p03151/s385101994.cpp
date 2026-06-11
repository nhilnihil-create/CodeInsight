#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#define LL long long
using namespace std;

const int N = 200010;
int a[N], b[N], c[N], n, cnt, cnt1;
LL t, t1, ans;

int main() 
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	
	for(int i = 1; i <= n; i++)
	{
		if(a[i] < b[i])
		{
			t += b[i] - a[i];
			cnt ++;
		} 
		if(a[i] > b[i])
		{
			t1 += a[i] - b[i];
			c[++cnt1] = a[i] - b[i];
		}
	}
	if(cnt == 0) cout << 0 << endl;
	else if(t1 < t) cout << -1 << endl;
	else {
		sort(c + 1, c + cnt1 + 1);
		int i;
		for(i = cnt1; i >= 1; i--){
			ans += c[i];
			if(ans >= t) break;
		}
		cout << cnt + cnt1 - i + 1 << endl;
	}
	return 0;
}