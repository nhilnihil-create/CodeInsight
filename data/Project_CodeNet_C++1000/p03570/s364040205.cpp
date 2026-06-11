#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
using namespace std;

char str[200010];
int dep[200010];
int xval[200010];
bool vst[1 << 27];
vector <int> v[200010];
bool vis[1 << 27];
map <int, int> mp;
int ct;

int Get(int arg) {
	int &id = mp[arg];
	if (!id) id = ++ct;
	return id;
}

int main() {
	scanf("%s", str + 1);
	for (int i = 1; str[i]; ++i) {
		xval[i] = xval[i - 1] ^ (1 << (str[i] - 'a'));
		int ind = Get(xval[i]);
		v[ind].push_back(i);
		vst[xval[i]] = 1;
	}
	dep[0] = 0;
	if (xval[strlen(str + 1)] == 0) {
		puts("1");
		return 0;
	}
	queue <int> q;
	q.push(0);
	while (!q.empty()) {
		int fr = q.front(); q.pop();
		for (int i = 0; i < 26; ++i) {
			int tt = xval[fr] ^ (1 << i);
			if (vis[tt] || !vst[tt]) continue;
			int prv = tt;
			tt = Get(tt);	
			for (auto j : v[tt]) {
				if (j > fr) {
					vis[prv] = 1;
					dep[j] = dep[fr] + 1;
					q.push(j);
				}
			}
		}
	}
	printf("%d", dep[strlen(str + 1)]);
	return 0;
}