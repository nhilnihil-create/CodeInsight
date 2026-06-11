#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

typedef pair<char, char> P;
int N, Q;
string label;
P command[200000];
int leftpos, rightpos;

bool left_f(int a) {
	int nowpos = a;
	for (int i = 0; i < Q; i++) {
		if (label[nowpos] == command[i].first) {
			if (command[i].second == 'L')nowpos--;
			else nowpos++;
		}
		if (nowpos == -1)return true;
	}
	return false;
}

bool right_f(int a) {
	int nowpos = a;
	for (int i = 0; i < Q; i++) {
		if (label[nowpos] == command[i].first) {
			if (command[i].second == 'L')nowpos--;
			else nowpos++;
		}
		if (nowpos == N)return true;
	}
	return false;
}

int main() {
	cin >> N >> Q >> label;
	for (int i = 0; i < Q; i++) {
		cin >> command[i].first >> command[i].second;
	}

	//左からの二分探索

	int u = N, l = -1;
	for (int i = 0; i < 40; i++) {
		int mid = (u + l) / 2;
		if (left_f(mid))l = mid;
		else u = mid;
	}
	if (left_f(u))leftpos = u;
	else leftpos = l;

	//右からの二分探索

	u = N, l = -1;
	for (int i = 0; i < 40; i++) {
		int mid = (u + l) / 2;
		if (right_f(mid))u = mid;
		else l = mid;
	}
	if (right_f(l))rightpos = l;
	else rightpos = u;

	cout << rightpos - leftpos - 1 << endl;
	
	return 0;
}