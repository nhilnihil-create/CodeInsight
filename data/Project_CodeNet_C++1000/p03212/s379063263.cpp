#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
	cout << fixed << setprecision(10);
	ll n;
	cin >> n;
	ll copy = n;
	int keta = 0;
	while(copy>0){
		copy /= 10;
		keta++;
	}
	int ans = 0;
	queue<string> que;
	que.push("7");
	que.push("5");
	que.push("3");
	while(1){
		string ss = que.front();
		que.pop();
		if((int)ss.size() > keta) break;
		set<char> sc;
		rep(i,ss.size()) sc.insert(ss[i]);
		if(sc.size() == 3 && atoi(ss.c_str()) <= n) ans ++;
		string s1 = "7", s2 = "5", s3 = "3";
		que.push(ss+s1); que.push(ss+s2); que.push(ss+s3);
	}
	cout << ans << endl;
	return 0;
}