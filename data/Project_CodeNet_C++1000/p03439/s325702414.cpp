#include <bits/stdc++.h>
using namespace std;
using ll = long long;

enum {
	MALE, FEMALE
};

int main(){
	int N;
	cin >> N;
	
	int current, before, before_i;
	// [ok, ng)
	int ok = 0, ng = N;
	for(int i=0;i<20;i++) {
		string s;
		if(i == 0) {
			cout << 0 << endl;
			cin >> s;
			if(s == "Vacant") {
				return 0;
			} else if(s == "Male") {
				current = MALE;
			} else if(s == "Female") {
				current = FEMALE;
			}
			before = current;
			before_i = 0;
			continue;
		}

		int mid = (ok + ng) / 2;
		cout << mid << endl;
		cin >> s;
		if(s == "Male") {
			current = MALE;
		} else if(s == "Female") {
			current = FEMALE;
		} else {
			return 0;
		}

		if((mid - before_i) % 2 == 0) {
			if(before == current) {
				// 次の探索範囲は[mid, ng)
				if(mid >= before_i) {
					ok = mid;
				} else {
					ng = mid;
				}
			} else {
				// 次の探索範囲は[ok, mid)
				if(mid >= before_i) {
					ng = mid;
				} else {
					ok = mid;
				}
			}
		} else {
			if(before == current) {
				if(mid >= before_i) {
					ng = mid;
				} else {
					ok = mid;
				}
			} else {
				if(mid >= before_i) {
					ok = mid;
				} else {
					ng = mid;
				}
			}
		}
		before = current;
		before_i = mid;
	}
}