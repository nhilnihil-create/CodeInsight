// ohainiさんの写経
#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
using P = pair<int,int>;
//Write From this Line

int main()
{
	int N;
	cin >> N;
	map<int,int> m;
	m[0]++;
	for(int i = 0; i < N; i++) {
		int t;
		cin >> t;
		m[t]++;
	}
	int ans = 100;
	vector<int> q;
	int cnt = 1;
	for(auto x:m){
		if(x.second>=3 || (x.first == 0 && x.second >= 2)|| (x.first == 12 && x.second >=2)){
			ans = 0;
			break;
		} else {
			if(x.second==2){
				q.push_back(x.first);
				q.push_back(24-x.first);
			}
			if(x.second == 1){
				if(cnt) q.push_back(x.first);
				else q.push_back(24-x.first);
				cnt = 1 - cnt;
			}
			sort(q.begin(),q.end());
			for(int i = 0; i < (int)q.size()-1; i++){
				chmin(ans,q[i+1]-q[i]);
			}
			chmin(ans,24-*(q.end()-1));
		}
	}
	cout << ans << endl;
}
