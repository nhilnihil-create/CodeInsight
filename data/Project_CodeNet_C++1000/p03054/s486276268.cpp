#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m,v,x,y;
	string f,s;
	cin >> n >> m >> v;
	cin >> y >> x;
	cin >> f >> s;
	int x1=x,y1=y;
	for(int i = 0 ; i < v ; i += 1){
		if(f[i] == 'R'){
			x1 += 1;
		}
		if(x1 == m+1){
			cout << "NO";
			return 0;
		}
		if(s[i] == 'L' && x1 > 1){
			x1 -= 1;
		}
	}
	x1=x,y1=y;
	for(int i = 0 ; i < v ; i += 1){
		if(f[i] == 'D'){
			y1 += 1;
		}
		if(y1 == n+1){
			cout << "NO";
			return 0;
		}
		if(s[i] == 'U' && y1 > 1){
			y1 -= 1;
		}
	}
	x1=x,y1=y;
	for(int i = 0 ; i < v ; i += 1){
		if(f[i] == 'L'){
			x1 -= 1;
		}
		if(x1 == 0){
			cout << "NO";
			return 0;
		}
		if(s[i] == 'R' && x1 < m){
			x1 += 1;
		}
	}
	x1=x,y1=y;
	for(int i = 0 ; i < v ; i += 1){
		if(f[i] == 'U'){
			y1 -= 1;
		}
		if(y1 == 0){
			cout << "NO";
			return 0;
		}
		if(s[i] == 'D' && y1 < n){
			y1 += 1;
		}
	}
	cout << "YES";
}