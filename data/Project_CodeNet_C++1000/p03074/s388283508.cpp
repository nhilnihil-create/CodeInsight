#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repn(i, n) for (int i = 0; i <= (int)(n); i++)
#define srep(i, l, n) for (int i = l; i < (int)(n); i++)
#define srepn(i, l, n) for (int i = l; i <= (int)(n); i++)
#define pb push_back 
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int MOD = 1000000007;
const int INF = 1e9;
#define PI 3.14159265369;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};

int main(){
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int now = 1;
	int cnt = 0;
	vector<int> num;
	rep(i,n){
		if(now==s[i]-'0') cnt++;
		else{
			num.push_back(cnt);
			cnt = 1;
			now = 1 - now;
		}
	}
	num.push_back(cnt);
	if(num.size()%2==0) num.push_back(0);

	vector<int> sum(num.size()+1);
	sum[0] = 0;
	rep(i, num.size()){
		sum[i+1] = sum[i] + num[i];
	}

	int tmp = 0;
	int add = 2*k+1;
	int ans = 0;

	for(int i = 0; i < num.size(); i+=2){
		int left = i;
		int right = min(i+add, (int)num.size());

		tmp = sum[right] - sum[left];
		chmax(ans, tmp);
	}

	cout << ans << endl;
}