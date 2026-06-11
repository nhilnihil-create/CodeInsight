#include <bits/stdc++.h>
using namespace std;

int n, ans, countN;
string s;
bool leftstr, rightstr;

int main() {
	cin >> n >> s;

	for(int i=1; i<n; i++){
		countN=0;
		for(char ele='a'; ele<='z'; ele++){
			leftstr = false;
			rightstr = false;
			for(int j=0; j<i; j++){
				if(s[j] == ele){
					leftstr = true;
					break;
				}
			}

			for(int j=i; j<n; j++){
				if(s[j] == ele){
					rightstr = true;
					break;
				}
			}

			if(leftstr&&rightstr){
				countN++;
			}
		}
		ans = max(ans, countN);
	}
	cout << ans << endl;
}