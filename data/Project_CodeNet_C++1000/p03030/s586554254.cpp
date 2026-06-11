#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;

int main(){
	int n;
	cin >> n;
	vector<tuple<string, int, int>> rest(n);
	rep(i, n){
		string city;
		int score;
		cin >> city >> score;
		rest[i] = make_tuple(city, -score, i+1);
	}

	sort(rest.begin(), rest.end());
	for(auto i : rest){
		cout << get<2>(i) << endl;
	}
	return 0;
}