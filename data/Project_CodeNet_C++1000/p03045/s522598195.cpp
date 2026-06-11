/*
 * written by Yaqi Zhang (zhang623@wisc.edu)
 * University of Wisconsin-Madison
 * 2020
 */
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

const int MAXN = 100005;
int parents[MAXN];
int sizes[MAXN];
int ans;

int find(int x) {
    return parents[x] == x ? x : (parents[x] = find(parents[x]));
}


void unite(int x, int y) {
    int rx = find(x), ry = find(y);
    if(rx != ry) {
        if(sizes[rx] > sizes[ry]) swap(rx, ry);
         sizes[ry] += sizes[rx];
        parents[rx] = ry;
		--ans;
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        sizes[i] = 1;
        parents[i] = i;
    }
	ans = n;
    for(int i = 0; i < m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        unite(x, y);
    }
    cout << ans << endl;
    return 0;
}

