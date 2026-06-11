#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

vector<int> parse(int n, string& s) {
    char c = s[0];
    int tmp = 1;
    vector<int> res;
    for (int i = 1; i < n; i++) {
        if (s[i] != c) {
            c = s[i];
            res.push_back(tmp);
            tmp = 1;
        } else {
            tmp++;
        }
    }
    res.push_back(tmp);
    return res;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, k;
	string s;
	cin >> n >> k >> s;
	vector<int> par = parse(n, s);
	int m = par.size(), ans = 0;
	if(s[0] == '1') ans += par[0];
	if(m%2 != (s[0]-'0')) par.push_back(0);
	int sum = 0, cnt = 0;
	queue<int> q;
	for(int i = (s[0] - '0'); i < m; i+=2){
		if(cnt >= k){
			int now = q.front();
			q.pop();
			sum -= now;
			if(cnt != k){
				now = q.front();
				q.pop();
				sum -= now;
			}
		}
		++cnt;
		q.push(par[i]);
		q.push(par[i+1]);
		sum += par[i] + par[i+1];
		chmax(ans, sum);
	}
	cout << ans << endl;
	return 0;
}
