#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <deque>
#include <cstring>
//#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define IOS ios::sync_with_stdio(0);cin.tie(0);
#define de(x,y) cout<<#x<<" :"<<x<<y;
#define int long long
#define SZ(xx) ((int)xx.size())
#define lowbit(xx) (xx&(-xx))
#define pb push_back
typedef pair<int,int> pii;

const int maxn = 4e5+5;
const int mod =  1e9 + 7;
int arr[maxn];

struct Bit_Tree {
	int bit[maxn] = {};
	
	void upd(int x,int val) {
		for (int i = x; i < maxn; i += lowbit(i)) bit[i] = (bit[i] + val) % mod;
	}	
	
	int qry(int l) {
		int ret = 0;
		for (int i = l; i; i -= lowbit(i)) ret = (ret + bit[i]) % mod;
		return ret;	
	}	
} bit;

main() {
	IOS
	int n, k;
	cin >> n >> k;
	k++;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	bit.upd(1, 1);
	bit.upd(min(k, 1 + arr[1]) + 1, -1);
	for (int i = 2; i <= n; i++) {
		if (arr[i] == 0) continue;
		for (int j = k; j >= 1; j--) {
			int val = bit.qry(j);
			int r = min(j + arr[i], k) + 1;
//			cout << j << " " << r << " " << val << "\n";
			bit.upd(j, val);	 
			bit.upd(r, -val + mod);
			bit.upd(j, -val + mod);
			bit.upd(j+1, val);
//			cout << val << " ";
		}	
//		cout << "\n"; 
	}
//	for (int i = 1; i <= k; i++) cout << bit.qry(i) << " \n"[i==k];
	
	cout << bit.qry(k) << "\n";
	
}

