#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> e;
vector<int> color;

bool check(int v, int c){
	color[v] = c;
	bool res = true;
	for(auto&& i : e[v]){
		if(color[i] == c) return false;
		else if(color[i] == 0) res &= check(i, -c);
	}
	return res;
}

int main(){
	long long n, m, ans = 0;
	cin >> n >> m;
	e = vector<vector<int>>(n + 1);
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		e[x].emplace_back(y);
		e[y].emplace_back(x);
	}
	color = vector<int>(n + 1);
	bool f = check(1, 1);
	if(f){
		long long b = 0, w = 0;
		for(int i = 1; i <= n; i++){
			if(color[i] == 1) b++;
			else w++;
		}
		cout << b * w - m << endl;
	}else{
		cout << n * (n - 1) / 2 - m << endl;
	}
	return 0;
}
