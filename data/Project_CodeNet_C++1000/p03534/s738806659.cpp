#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PII;


int main() {
	string s;
	cin >> s;
	int cnt[3];
	cnt[0] = cnt[1] = cnt[2] = 0;
	for(int i=0; i<s.size(); i++)
		cnt[s[i] - 'a'] ++;
	int maxim = max(cnt[0], max(cnt[1], cnt[2]));
	int minim = min(cnt[0], min(cnt[1], cnt[2]));
	//cout << minim << " " << maxim << endl;
	if(maxim - minim <= 1)
		cout << "YES" << endl;
	else cout << "NO" << endl;
	
	return 0;
}