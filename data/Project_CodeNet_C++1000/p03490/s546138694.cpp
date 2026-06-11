#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <bitset>
using namespace std;
typedef long long i64;
typedef long double ld;
typedef pair<i64,i64> P;
#define rep(i,s,e) for(int i = (s);i <= (e);i++)

string s;
int x;
int y;

bitset<16010> bit[2];


int main(){
	cin >> s >> x >> y;
	x += 8000;
	y += 8000;
	vector<int> vec;
	vec.push_back(0);
	for(char c : s){
		if(c == 'T'){
			vec.push_back(0);
		}
		else{
			vec.back()++;
		}
	}
	bit[0][8000] = 1;
	bit[1][8000] = 1;
	for(int i = 0;i < vec.size();i++){
		if(i == 0){
			bit[i % 2] = (bit[i % 2] << vec[i]);
		}
		else{
			bit[i % 2] = (bit[i % 2] << vec[i]) | (bit[i % 2] >> vec[i]);
		}
	}

	if(bit[0][x] && bit[1][y]){
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}
}
