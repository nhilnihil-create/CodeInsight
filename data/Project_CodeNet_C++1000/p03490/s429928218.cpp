#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
const int sp = 8050;

string s;
int x, y, xsum, ysum, xt, yt;
bool turned = false;
bool direction = true;//true-x,false-y
int xboard[16100];
int yboard[16100];
int temp = 0;
queue<int> q;

void dp(int board[], int sum, int t) {
	for (int i = sp - sum; i <= sp + sum; i++) {
		if (board[i] == t) q.push(i);
	}
	while (q.size() != 0) {
		int i = q.front();
		board[i - temp] = board[i + temp] = t + 1;
		q.pop();
	}
}

void solv() {
	if (direction) {
		dp(xboard, xsum, xt);
		xsum += temp;
		xt++;
		temp = 0;
		direction = false;
	}
	else {
		dp(yboard, ysum, yt);
		ysum += temp;
		yt++;
		temp = 0;
		direction = true;
	}
}

int main() {
	cin >> s;
	cin >> x >> y;
	xt = yt = xboard[sp] = yboard[sp] = 1;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'F') {
			temp++;
		}
		else {
			if (!turned) {
				xboard[sp + temp] = xt + 1;
				xt++;
				xsum += temp;
				turned = true;
				temp = 0;
				direction = false;
			}
			else if (temp == 0) direction = !direction;
			else {
				solv();
			}
		}
	}
	if (temp != 0) {
		if (!turned) {
			xboard[sp + temp] = xt + 1;
			xt++;
			xsum += temp;
			turned = true;
			temp = 0;
			direction = false;
		}
		else solv();
	}

	if (xboard[sp + x] == xt && yboard[sp + y] == yt)cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}