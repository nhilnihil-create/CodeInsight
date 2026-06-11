#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_two_colors_card_game(void) {
	int n, m;
	string s[100];
	string t[100];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i];
	cin >> m;
	for (int i = 0; i < m; i++) cin >> t[i];

	string s_merge[100];
	int s_cnt[100] = { 0 };
	bool detect = false;
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == "None") continue;
		else {
			s_cnt[i]++;
			for (int j = i+1; j < n; j++) {
				if (s[i] == s[j]) {
					s_cnt[i]++;
					s[j] = "None";
				}
			}
			for (int k = 0; k < m; k++) {
				if (s[i] == t[k]) s_cnt[i]--;
			}
		}
		
		//cout << s_cnt[i] << endl;
		if (s_cnt[i] > max) max = s_cnt[i];
	}

	cout << max << endl;
	

}

int main()
{
	b_two_colors_card_game();
    return 0;
}