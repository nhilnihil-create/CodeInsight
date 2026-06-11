#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using v2 = vector<vector<int>>;
int N;

int main(){
	ll n;
	string s;
	cin >> n >> s;
	ll size = s.size();
	ll east = 0;
	ll west = 0;
	rep(i, size){
		if(s.at(i) == 'E') east++;
		if(s.at(i) == 'W') west++;
	}
	ll change_left = 0;
	ll change_right;
	if(s.at(0) == 'E') change_right = east-1;
	if(s.at(0) == 'W') change_right = east;
	ll sum = change_right+change_left;
	rep(i, size){
		if(i == 0) continue;
		if(s.at(i) == 'E') change_right--;
		if(s.at(i-1) == 'W') change_left++;
		if(change_right+change_left < sum) sum = change_right+change_left;
	}
	cout << sum << endl;
}
