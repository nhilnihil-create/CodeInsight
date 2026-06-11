#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define F first
#define S second

using namespace std;

int n;
vector < pair <int, int> > ans;

int main(){
	cin >> n;
	if(n % 2 == 0){
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				if(i + j != n + 1) ans.pb(mp(i , j));
			}
		}
	}
	else{
		for(int i = 1; i <= n; i++){
			for(int j = 1; j < i; j++){
				if(n - j != i){
					ans.pb(mp(i , j));
				}
			}
		}
	}
	cout << ans.size() << "\n";
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i].F << " " << ans[i].S << "\n";
	}
}