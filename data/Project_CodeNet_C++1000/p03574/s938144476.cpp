#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_minesweeper(void) {
	int h, w;
	char s[52][52] = { '.' };
	char o;

	cin >> h >> w;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> s[i][j];
		}
	}

	int bumb = 0;

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (s[i][j] == '#') {
				o = '#';
			}
			else {
				bumb = 0;
				for (int k = i - 1; k < i + 2; k++) {
					for (int l = j - 1; l < j + 2; l++) {
						if (s[k][l] == '#') bumb++;
					}
				}
				o = bumb+'0';
			}
			cout << o;
		}
		cout << endl;
		
	}
}

int main()
{
	b_minesweeper();
    return 0;
}