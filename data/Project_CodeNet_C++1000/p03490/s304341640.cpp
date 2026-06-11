#include <iostream>
#include <cstdio>
#define N 16005
using namespace std;

int x, y, c;
bool d, t[2][N], v[2][N];
string s;
int main()
{
	int i, j;
	cin >> s >> x >> y;
	v[1][8000] = 1;
	for (i = 0; s[i] == 'F'; i++);
	v[0][8000 + i] = 1;
	for (; i <= s.size(); i++) {
		if (s[i] == 'F') c++;
		else {
			for (j = c; j < N - c; j++) {
				t[d][j - c] = max(t[d][j - c], v[d][j]);
				t[d][j + c] = max(t[d][j + c], v[d][j]);
			}
			for (j = 0; j < N; j++) v[d][j] = t[d][j], t[d][j] = 0;
			c = 0;
			d = !d;
		}
	}
    cout << (v[0][x + 8000] & v[1][y + 8000] ? "Yes" : "No") << endl;
    return 0;
}