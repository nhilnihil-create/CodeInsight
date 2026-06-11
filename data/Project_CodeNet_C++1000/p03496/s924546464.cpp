#include <iostream>
#include <string>

using namespace std;

inline int length(int num) {
	return num >= 0 ? num : -num;
}

int main()
{
	/*
		まず全入力を取得。その際最大値と最小値のうち絶対値が大きい方を保持。
		それが最大値ならindex=0から並べていく。逆ならindex = n-1から。
		二回足したら最大値をそちらにシフト。
	
	*/
	int n;
	cin >> n;
	int longest = 0;
	int maxIndex = 1;
	int num;
	for (int i = 1; i <= n; i++) {
		cin >> num;
		if (length(longest) < length(num)) {
			longest = num;
			maxIndex = i;
		}
	}

	int start;
	int end;
	int dir;

	if (longest > 0) {
		start = 2;
		end = n;
		dir = 1;
	}
	else {
		start = n-1;
		end = 1;
		dir = -1;
	}
	string ans = to_string(2 * (n - 1)).append("\n");
	string str = to_string(maxIndex).append(" ").append(to_string(start)).append("\n");
	ans.append(str).append(str);

	for (int i = start + dir; i != end + dir; i += dir) {
		str = to_string(i - dir).append(" ").append(to_string(i)).append("\n");
		ans.append(str).append(str);
	}
	cout << ans;
}