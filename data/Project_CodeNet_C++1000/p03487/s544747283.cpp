#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n, m) for (int i = n; i >= m; i--)

int main(){
	unordered_map<int, int> T;
	int n;
	cin >> n;

	rep(i, n){
		int tmp;
		scanf("%d", &tmp);
		if(T.find(tmp) != T.end()){
			T[tmp] = T[tmp] + 1;
		}else{
			T[tmp] = 1;
		}
	}

	int cnt = 0;
	
	for (auto tmp2 : T){
		if(tmp2.first <= tmp2.second){
			cnt += tmp2.second - tmp2.first;
		}else{
			cnt += tmp2.second;
		}
	}	

	cout << cnt << endl;
}
