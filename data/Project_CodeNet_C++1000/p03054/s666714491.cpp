#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int H, W, n, sr, sc;
	cin >> H >> W >> n >> sr >> sc;
	string s, t;
	cin >> s >> t;
	bool ans = true;
	for(char c : "LRUD"){
		if(c == 'L'){
			int c1 = 0, c2 = 0;
			for(int i = 0; i < n; i++){
				c1 += (s[i] == c);
				if(sc + c2 - c1 <= 0){
					ans = false;
					break;
				}
				if(t[i] == 'R' && sc + c2 + 1 - c1 <= W) c2++;
			}
		}
		else if(c == 'R'){
			int c1 = 0, c2 = 0;
			for(int i = 0; i < n; i++){
				c1 += (s[i] == c);
				if(sc + c1 - c2 > W){
					ans = false;
					break;
				}
				if(t[i] == 'L' && sc + c1 - c2 - 1 > 0) c2++;
			}
		}
		else if(c == 'U'){
			int c1 = 0, c2 = 0;
			for(int i = 0; i < n; i++){
				c1 += (s[i] == c);
				if(sr + c2 - c1 <= 0){
					ans = false;
					break;
				}
				if(t[i] == 'D' && sr + c2 + 1 - c1 <= H) c2++;
			}
		}
		else{
			int c1 = 0, c2 = 0;
			for(int i = 0; i < n; i++){
				c1 += (s[i] == c);
				if(sr + c1 - c2 > H){
					ans = false;
					break;
				}
				if(t[i] == 'U' && sr + c1 - c2 - 1 > 0) c2++;
			}
		}
	}
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}