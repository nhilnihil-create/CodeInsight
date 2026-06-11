#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<tuple>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<deque>
#include<cmath>
#include<stack>
#include<string.h>
#include <iomanip>
#define rep(i,n) for(int i = 0;i<n;i++)
using ll = long long; 
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
	int n;
	cin >> n;
	vector<int>v(n);
	rep(i,n) cin >> v[i];
	//cnt1は偶数,cnt2は奇数
	vector<int>cnt1(100010),cnt2(100010);
	rep(i,n) {
		if(i%2 == 0) {
			cnt1[v[i]]++;
		}
		if(i%2 == 1) {
			cnt2[v[i]]++;
		}
	}
	int mode1 = -1;//偶数の最頻値
	int tmp1 = -1;
	for(int i = 0;i<100010;i++) {
		if(tmp1<=cnt1[i]) {
			tmp1 = cnt1[i];
			mode1 = i;
		}
	}
	
	int mode2 = -1;//偶数で2番目に大きい最頻値
	int tmp2 = -1;
	for(int i = 0;i<100010;i++) {
		if(i != mode1 && tmp2<cnt1[i]) {
			tmp2 = cnt1[i];
			mode2 = i;
 		}
	}
	
	int mode3 = -1;//奇数の最頻値
	int tmp3 = -1;
	for(int i = 0;i<100010;i++) {
		if(tmp3<=cnt2[i]) {
			tmp3 = cnt2[i];
			mode3 = i;
		}
	}
	int mode4 = -1;//奇数で2番目に大きい最頻値
	int tmp4 = -1;
	for(int i = 0;i<100010;i++) {
		if(i != mode3 && tmp4<cnt2[i]) {
			tmp4 = cnt2[i];
			mode4 = i;
 		}
	}
	int ans = 0;
	//偶数番目の配列と奇数番目の配列の最頻値が互いに異なるとき
	if(mode1 != mode3) {
		rep(i,n) {
			if(i%2==0) {
				if(v[i] != mode1) ans++;
			}
			if(i%2 == 1) {
				if(v[i] != mode3) ans++;
			}
		}
		cout << ans << endl;
		return 0;
	}
	int ans2 = 0;
	int ans3 = 0;
	//偶数番目と奇数番目で最頻値が同じとき
	//２番目に大きい最頻値を使って２通り試して最小値をとる
	if(mode1 == mode3) {
		rep(i,n) {
			if(i%2==0) {
				if(v[i] != mode1) ans2++;
			}
			if(i%2 == 1) {
				if(v[i] != mode4) ans2++;
			}
		}
		rep(i,n) {
			if(i%2==0) {
				if(v[i] != mode2) ans3++;
			}
			if(i%2 == 1) {
				if(v[i] != mode3) ans3++;
			}
		}
		cout << min(ans2,ans3) << endl;
		return 0;
	}
}
