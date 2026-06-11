#include<bits/stdc++.h>
using namespace std;
const int Z = 26 + 13, maxN = 2e5 + 13;
int n, q;
char d[maxN], t[maxN];
string s;
vector<int> vec[Z];

bool canl (int x) {
    int cur = x;
    for (int i = 0; i < q; i++)
	if (t[i] == s[cur]) {
	    if (d[i] == 'L')
		cur--;
	    else
		cur++;
	    if (cur == -1)
		return 1;
	    if (cur == n)
		return 0;
	}
    return 0;
}

bool canr (int x) {
    int cur = x;
    for (int i = 0; i < q; i++)
	if (t[i] == s[cur]) {
	    if (d[i] == 'L')
		cur--;
	    else
		cur++;
	    if (cur == n)
		return 1;
	    if (cur == -1)
		return 0;
	}
    return 0;
}


		
int main () {
    cin >> n >> q;
    cin >> s;
    for (int i = 0; i < q; i++) {
	cin >> t[i] >> d[i];
    }

    int l = -1, r = n;
    while (r - l > 1) {
	int mid = l + r >> 1;
	if (canl(mid))
	    l = mid;
	else
	    r = mid;
    }

    int st = r;
    l = -2, r = n;
    while (r - l > 1) {
	int mid = l + r >> 1;
	if (canr(mid))
	    r = mid;
	else
	    l = mid;
    }
    int en = r;
    cout << en - st << endl;
	
}
