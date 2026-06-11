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
vector<P> graph[100100];
int main()
{
	int n;
	cin >> n;
	rep(i,n-1){
		int a, b, w;
		cin >> a >> b >> w;
		--a, --b;
		graph[a].push_back({b,w});
		graph[b].push_back({a,w});
	}
	// 0 を黒にするって決めちゃえば後は自然に全部決まりそう
	vector<int> ans(n,-1);
	ans[0] = 0;
	vector<bool> seen(n,false);
	seen[0] = true;

	queue<int> que;
	que.push(0);
	while(!que.empty()){
		int p = que.front();
		que.pop();
		// p からいけるところ全部
		for(auto x : graph[p]){
			if(seen[x.first]) continue;
			// ans[p] が 0 のとき
			if(ans[p] == 0){
				// sedcond が 偶数ならok
				if(x.second % 2 == 0){
					ans[x.first] = 0;
				} else {
					ans[x.first] = 1;
				}
			} else {
				if(x.second % 2 == 1){
					ans[x.first] = 0;
				} else {
					ans[x.first] = 1;
				}
			}
			seen[x.first] = true;
			que.push(x.first);
		}
	} 
	rep(i,n){
		cout << ans[i] << endl;
	}
}
