#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {

	//入力
	string S;
	cin >> S;

	//十分に大きな数
	int ans = S.size();
	
	//iは最初の色(0 or 1)
	for (int i = 0; i < 2; i++) {
		
		//最初の色がiの時の入れ替える回数
		int cnt = 0;

		//jは今見ているタイル
		for (int j = 0; j < S.size(); j++) {

			if (j % 2 == 0 && S[j] != char(i + '0')) {
				cnt++;
			}
			else if (j % 2 == 1 && S[j] == char(i + '0')) {
				cnt++;
			}

		}

		ans = min(cnt, ans);

	}

	cout << ans << endl;

}