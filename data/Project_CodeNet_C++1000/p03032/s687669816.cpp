#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

void coY() {cout <<"Yes"<<endl;}
void coN(){cout <<"No"<<endl;}
 
//Write From this Line

//const ll mod = 1e9+7;
//const ll mod = 998244353;
int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	rep(i, n)cin>>v[i];

	ll ans = INT_MIN;
	for(int left = 0; left <= n; left ++){
		for(int right = 0; right <= n; right++){
			ll tmp = 0;
			if(left + right > n) continue;
			int back = (k - left - right); // back 個まで無視出来る
			if(back < 0) continue;
			priority_queue<int,vector<int>, greater<int>> q;
			rep(i,left){
				q.push(v[i]);
			}
			rep(i,right){
				q.push(v[n-1-i]);
			}
			int count = 0;
			rep(i,left+right){
				// back個まで戻せる
				int t = q.top(); q.pop();
				if(t < 0 && count < back){
					count ++;
					continue;
				}
				else {
					tmp += t;
				}
			}
			chmax(ans,tmp);
		}
	}
	cout << ans << endl;
}
