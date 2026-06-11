#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#define maxn 200005
using namespace std;
int n, b[maxn], arr[maxn], s[maxn], real[maxn];
map <int, int> mp;
int C[maxn];
void add(int x){
	for (; x <= 2 * n + 1; x += x & -x)
		C[x] ++;
}
int sum(int x){
	int ans = 0;
	for (; x; x -= x & -x)
		ans += C[x];
	return ans;
}
int main(){
	cin >> n;
	long long ok = (1LL * (n + 1) * n / 2 + 1) / 2;
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &b[i]);
		arr[i] = b[i];
	}
	sort(arr + 1, arr + 1 + n);
	int M = 0;
	for (int i = 1; i <= n; ++ i)
		if (arr[i] != arr[i - 1]){
			mp[arr[i]] = ++ M;
			real[M] = arr[i];
		}
	for (int i = 1; i <= n; ++ i)
		b[i] = mp[b[i]];
	int l = 1, r = M, ans;
	while (l <= r){
		int m = l + r >> 1;
		for (int i = 1; i <= n; ++ i)
			s[i] = s[i - 1] + (b[i] >= m ? 1 : -1);
		for (int i = 1; i <= 2 * n + 1; ++ i)
			C[i] = 0;
		long long cnt = 0;
		add(n + 1);
		for (int i = 1; i <= n; ++ i){
			cnt += sum(s[i] + n + 1);
			add(s[i] + n + 1);
		}
		if (cnt >= ok){
			ans = m;
			l = m + 1;
		}
		else
			r = m - 1;
	}
	cout << real[ans] << endl;
}
