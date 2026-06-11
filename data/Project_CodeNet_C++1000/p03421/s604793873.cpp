#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
using namespace std;
typedef long long i64;
typedef long double ld;
typedef pair<i64,i64> P;
#define rep(i,s,e) for(int i = (s);i <= (e);i++)

i64 n;
i64 a;
i64 b;

int main(){
	cin >> n >> a >> b;
	if(a * b < n || a + b - 1 > n){
		cout << -1 << endl;
		return 0;
	}
	vector<int> ans;
	int cou = 0;
	n -= a;
	for(int i = 0;i < a;i++){
		if(cou + b - 1 <= n){
			for(int j = 0;j < b;j++){
				ans.push_back(cou + b - j + i);
			} cou += b - 1;
		}
		else
		{
			for(int j = 0;j <= n - cou;j++){
				ans.push_back(n - j + i + 1);
			}
			cou = n;
		}

	}
	if(ans.size() < n + a){
		 cout << -1 << endl;
	}
	else{
		for(int a : ans){
			cout << a << " ";
		}
		cout << endl;
	}
}
