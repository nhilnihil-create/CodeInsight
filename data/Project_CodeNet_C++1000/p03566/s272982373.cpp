/**********************************************************
 * サンプル通すのに丸一日かかったよ(泣)
***********************************************************/

#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = ((int)(n)-1); i >= 0; i--)
#define all(x) (x).begin(),(x).end()

using namespace std;
using ll = long long;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> P;
 
const int INF = 1e9;
//const ll INF = 1e18;
const double EPS = 1e-10;
const int MOD = 1e9+7;
const double PI = acos(-1.0);

int main()
{
	int n;
	cin >> n;
	vector<int> t(n+1,0),v(n+1,0);

	for(int i = 1; i <= n; i++) cin >> t[i];
	for(int i = 1; i <= n; i++) cin >> v[i];
	for(int i = 1; i <= n; i++) t[i] += t[i-1];
	for(int i = 1; i <= n; i++) t[i] *= 2, v[i] *= 2;

	vector<int> g(t.back()+10,0);
	for(int i = 1; i <= n; i++) g[t[i]] = v[i];
	for(int i = 1; i <= n; i++){
		for(int j = t[i-1]+1; g[j] != v[i]; j++) g[j] = v[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = t[i-1]; g[j] != v[i]; j++) g[j] = min(g[j],v[i]);
	}

	g[0] = g[t.back()] = 0;
	for(int x = 1; x < t.back(); x++){
		g[x] = min(g[x],g[x-1]+1);
	}
	for(int x = t.back()-1; x >= 0; x--){
		g[x] = min(g[x],g[x+1]+1);
	}
/*
	for(int i = 0; i <= t.back(); i++){
		cout << i << ":";
		for(int j = 0; j < g[i]; j++){
			printf("%3d",g[i]);
		}
		cout << endl;
	}
*/
	double ans = 0,tmp;
	for(int i = 0; i < t.back(); ){
		tmp = i;
		//cout << "======================================" << endl;
		if(g[i] == g[i+1]){
			while(g[i] == g[i+1]) i++;
			ans += (g[i]+g[tmp])*(i-tmp)/8.0;
			//cout << "a" << endl;
		}else if(g[i] > g[i+1]){
			while(g[i] > g[i+1]) i++;
			ans += (g[i]+g[tmp])*(i-tmp)/8.0;
			//cout << "b" << endl;
		}else{
			while(g[i] < g[i+1]) i++;
			ans += (g[i]+g[tmp])*(i-tmp)/8.0;
			//cout << "c" << endl;
		}
		//cout << i << " " << tmp << endl;
		//cout << ans << endl;
	}
	//cout << "============================================" << endl;
	cout << fixed << ans << endl;
	return 0;
}