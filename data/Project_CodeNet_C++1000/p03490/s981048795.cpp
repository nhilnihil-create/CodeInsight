#include<bits/stdc++.h>
using namespace std;
const int maxn = 8015;

string s;

int x, y;
int dpx[maxn * 2], dpy[maxn * 2];
int upd[maxn * 2];

int main() {
	cin >> s >> x >> y;
	s += 'T';
	int n = s.size();
	dpx[n] = 1;
	dpy[n] = 1;
	int cnt = 0;
	int u = 1;
	int i = 0;
	while(s[i] == 'F')
		i++;
	x -= i;
	for(; i <= n; i++) {
		if(s[i] == 'F')
			cnt++;
		else {
			fill(upd, upd + 2 * n + 1, 0);
			if(u == 1) {
				for(int i = 0; i <= 2 * n; i++) {
					if(i - cnt >= 0)
						upd[i] = dpx[i - cnt];
					if(i + cnt <= 2 * n)
						upd[i] |= dpx[i + cnt];
				}
				for(int i = 0; i <= 2 * n; i++)
					dpx[i] = upd[i];
			}
			else {
				for(int i = 0; i <= 2 * n; i++) {
					if(i - cnt >= 0)
						upd[i] = dpy[i - cnt];
					if(i + cnt <= 2 * n)
						upd[i] |= dpy[i + cnt];
				}
				for(int i = 0; i <= 2 * n; i++)
					dpy[i] = upd[i];
			}
			u = 1 ^ u;
			cnt = 0;
		}
	}
	if(dpx[n + x] && dpy[n + y])
		return cout << "Yes", 0;
	return cout << "No", 0;
}