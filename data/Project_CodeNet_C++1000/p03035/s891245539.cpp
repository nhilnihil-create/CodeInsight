  
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4") // wonderful

// https://leetcode.com/problems/count-complete-tree-nodes/
#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

	int age, cost; cin >> age >> cost;

	if (age > 12)
		cout << cost;
	else if (6 <= age && age <= 12)
	{
		double res = cost / 2;
		cout << res;
	}
	else if (age < 6)
		cout << 0;
	
    return 0;
}