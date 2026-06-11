#include <bits/stdc++.h>
#define ALL(A) (A).begin(),(A).end()
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)

const ll mod = 1e9+7;
const ll INF = 2*1e18;
const int inf = 1e9+7;

using namespace std;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.size();
	vector<int> cnt(3);
	for(int i=0;i<n;i++){
		if(s[i]=='a')cnt[0]++;
		else if(s[i]=='b')cnt[1]++;
		else cnt[2]++;
	}
	sort(ALL(cnt));
	if(cnt[2]-cnt[0] <2)cout << "YES" << endl;
	else cout << "NO" << endl;
}