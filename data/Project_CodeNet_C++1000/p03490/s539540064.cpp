#include <bits/stdc++.h>
using namespace std;

const int M = 8000 + 50, N = 2 * 9000 + 50;
bool dp1[M][N], dp2[M][N];
string s;
int x, y;
vector<int> h[2];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin >> s >> x >> y;
	int l = 0, r = 0;
	bool p = false;
	for (int i = 0; i < s.size(); i++){
		if(s[i] == 'T'){
			if(!p){
				x -= l;
				l = 0;
				p = 1;
				r = 1 - r;
				continue;
			}
			if(l != 0){
				h[r].push_back(l);
				l = 0;
			}
			r = 1 - r;
		}
		else
			l++;
	}
	if(l > 0){
		if(!p)
			x -= l;
		else
			h[r].push_back(l);
	}
	int mid = 8000 + 10;
	
	for (int i = 0; i < h[0].size(); i++){
		if(i == 0){
			dp1[0][mid + h[0][0]] = 1;
			dp1[0][mid - h[0][0]] = 1;
		}else{
			for (int j = 0; j < N; j++){
				if(j + h[0][i] < N)
					dp1[i][j] |= dp1[i - 1][j + h[0][i]];
				if(j - h[0][i] >= 0)
					dp1[i][j] |= dp1[i - 1][j - h[0][i]];
			}
		}	
	}
	
	for (int i = 0; i < h[1].size(); i++){
		if(i == 0){
			dp2[0][mid + h[1][0]] = 1;
			dp2[0][mid - h[1][0]] = 1;
		}else{
			for (int j = 0; j < N; j++){
				if(j + h[1][i] < N)
					dp2[i][j] |= dp2[i - 1][j + h[1][i]];
				if(j - h[1][i] >= 0)
					dp2[i][j] |= dp2[i - 1][j - h[1][i]];
			}
		}	
	}
	
	bool t1;
	if(h[0].size() == 0){
		if(x != 0)
			return cout << "No", 0;
		t1 = 1;
	}else
		t1 = dp1[h[0].size() - 1][mid + x];
	bool t2;
	if(h[1].size() == 0){
		if(y != 0)
			return cout << "No", 0;
		t2 = 1;
	}else
		t2 = dp2[h[1].size() - 1][mid + y];
						
	if(t1 && t2)
		cout << "Yes";
	else
		cout << "No";
}

