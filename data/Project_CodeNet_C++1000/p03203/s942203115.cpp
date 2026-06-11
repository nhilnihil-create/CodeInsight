#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

typedef pair<long long int, long long int> P;

long long int INF = 1e18;
long long int MOD = 1e9 + 7;

vector<int> pos[210000];
unordered_map<long long int, int> m;

long long int ret(long long int X, long long int Y){
	return X * 1e9 + Y;
}

int main(){
	
	int H, W, N;
	cin >> H >> W >> N;
	
	for(int i = 0; i < N; i++){
		int X, Y;
		cin >> X >> Y;
		pos[Y].push_back(X);
		m[ret(X, Y)] = 1;
	}
	
	for(int i = 0; i < 210000; i++){
		sort(pos[i].begin(), pos[i].end());
		pos[i].push_back(H + 1);
		m[ret(H + 1, i)] = 1;
	}
	
	int posx = 1, posy = 1;
	int ans = 1000000;
	bool flag = true;
	
	while(true){
		if(flag){
			for(int i = 0; i < pos[posy].size(); i++){
				if(pos[posy][i] > posx){
					ans = min(ans, pos[posy][i] - 1);
					break;
				}
			}
		}
		if(m.find(ret(posx + 1, posy)) == m.end()){
			posx += 1;
		}else{
			break;
		}
		if(m.find(ret(posx, posy + 1)) == m.end()){
			posy += 1;
			flag = true;
		}else{
			flag = false;
		}
		if(posy > W){
			break;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
