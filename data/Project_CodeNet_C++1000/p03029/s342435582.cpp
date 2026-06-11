  
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4") // wonderful

// https://leetcode.com/problems/count-complete-tree-nodes/
#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

	int apple, pieces; 
	cin >> apple >> pieces;

	pieces += (apple * 3);

	int res = 0;

	while (pieces >= 2) {
		res++;
		pieces -= 2;
	}

	cout << res;
	

    return 0;
}