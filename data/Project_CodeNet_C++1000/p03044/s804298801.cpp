#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<string>
#include<cmath>
#include<set>
#include<queue>
#include<deque>
#include<bitset>
#include<iomanip>
#include<cctype>
#include<map>
#include<cstring>
#include<bitset>
#include<cassert>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,a,b) for (int (i)=a;(i)<(b);(i)++)
#define all(x) (x).begin(),(x).end()

using namespace std;
using ll = long long int;

const int inf = 1001001000;
const long long int Inf = 1001001001001001000;



void print(vector<vector<int>> a){
	for (int i = 0; i < a.size(); i++)
	{
		for (int j=0;j<a[i].size();j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void print(vector<vector<long long int>> a){
	for (int i=0;i<a.size();i++){
		for (int j=0;j<a[i].size();j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void print(vector<int> a){
    int n = a.size();
    for (int j=0;j<n;j++) {
        if (j != n-1) cout << a[j] << " ";
        else cout << a[j] << endl;
    }
}

void print(vector<long long int> a){
    int n = a.size();
    for (int j=0;j<n;j++) {
        if (j != n-1) cout << a[j] << " ";
        else cout << a[j] << endl;
    }
}

void print(set<int> a){
	for (auto x:a)
		cout << x << " ";
	cout << endl;
}

//深さ優先探索のテンプレ.デフォルトでは参照渡ししたsetに探索済みの頂点が格納される.
//graphは隣接リスト.vは探索開始地点.seenは空のセット.
void dfs(vector<vector<int>> &graph, int b, int v, map<pair<int, int>, ll> &w, vector<int> &ans){
	if ((ans[b] + w[pair<int, int>(min(v, b), max(v, b))]) % 2 == 0)
	{
		// cout << "even : " << b << " " << v << " " << w[pair<int, int>(min(v, b), max(v, b))] << endl;
		ans[v] = 0;
	}
	else
	{
		// cout << "odd : " << b << " " << v << " " << w[pair<int, int>(min(v, b), max(v, b))] << endl;
		ans[v] = 1;
	}
	for (int i = 0; i < graph[v].size(); i++)
	{
		int nxt = graph[v][i];
		if (ans[nxt] != -1) continue;
		dfs(graph, v, nxt, w, ans);
	}
}

int main(){
	int n;
	cin >> n;
	vector<vector<int>> graph(n);
	map<pair<int, int>, ll> w;
	rep(i,n-1){
		int a, b;
		ll c;
		cin >> a >> b >> c;
		a--;
		b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
		w[pair<int, int>(min(a, b), max(a, b))] = c;
	}
	w[pair<int, int>(0, 0)] = 0;
	vector<int> ans(n, -1);
	ans[0] = 0;
	dfs(graph, 0, 0, w, ans);
	rep(i, n) cout << ans[i] << endl;
}