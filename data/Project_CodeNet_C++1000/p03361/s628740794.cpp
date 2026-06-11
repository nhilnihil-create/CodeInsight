#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 60;
int h, w, dirx[4] = {1, -1, 0, 0}, diry[4] = {0, 0, 1, -1};
string s[maxn];
bool check;

int main(){
	cin >> h >> w;
	
	for(int i=0; i<h; i++)
		cin >> s[i];

	for(int i=0; i<h; i++){
		for(int j=0, temp; j<w; j++){
			if(s[i][j] == '.'){
				continue;
			}

			check = false;
			for(int k=0, x, y; k<4; k++){
				x = dirx[k]+j;
				y = diry[k]+i;
				if(x<0||x>=w||y<0||y>=h){
					continue;
				}
				if(s[y][x] == '#'){
					check = true;
				}
			}
			if(!check){
				cout << "No" << endl;
                return 0;
			}
		}
	}

	cout << "Yes" << endl;
  	return 0;
}