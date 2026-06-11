#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <map>
const int MOD = 1e9+7;
typedef long long ll;
using namespace std;

ll llmax(ll x, ll y){
	if (x > y) return x;
	return y;
}

ll llmin(ll x, ll y){
	if (x < y) return x;
	return y;
}

ll get_ans(int index1, int index2, ll x, vector<ll> &s, vector<ll> &t){
	if (s[index1] - x >= 0 == t[index2] - x >= 0){
		return llmax(abs(s[index1] - x), abs(t[index2] - x));
	}else{
		return llmax(abs(s[index1] - x), abs(t[index2] - x)) + llmin(abs(s[index1] - x), abs(t[index2] - x))*2;
	}
}


int main(){
	ll a, b, q;
	cin >> a >> b >> q;
	vector<ll> s(a);
	vector<ll> t(b);

	for (int i = 0; i < a; i++)	cin >> s[i];
	for (int i = 0; i < b; i++) cin >> t[i];

	for (int i = 0; i < q; i++){
		ll x;
		cin >> x;
		int index1 = lower_bound(s.begin(), s.end(), x) - s.begin();
		int index2 = lower_bound(t.begin(), t.end(), x) - t.begin();
		if (index1 == 0){
			if (index2 == 0){
				cout << get_ans(index1, index2, x, s, t) << endl;
			}else{
				cout << llmin(get_ans(index1, index2, x, s, t), get_ans(index1, index2-1, x, s, t)) << endl;
			}
		}else{
			if (index2 == 0){
				cout << llmin(get_ans(index1, index2, x, s, t), get_ans(index1-1, index2, x, s, t)) << endl;
			}else{
				cout << llmin(min(get_ans(index1, index2, x, s, t), get_ans(index1-1, index2, x, s, t)), llmin(get_ans(index1-1, index2-1, x, s, t), get_ans(index1, index2-1, x, s, t))) << endl;			
			}
		}
	}
	return 0;
}