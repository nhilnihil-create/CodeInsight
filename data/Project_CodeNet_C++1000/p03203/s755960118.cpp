#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 200005;
int pos[MAXN];

int main(){
	int h, w, n; scanf("%d %d %d",&h,&w,&n);
	for(int i=1; i<=h; i++) pos[i] = w + 1;
	for(int i=0; i<n; i++){
		int x, y; scanf("%d %d",&x,&y);
		pos[x] = min(pos[x], y);
	}
	int rng = 1;
	for(int i=2; i<=h; i++){
		if(pos[i] <= rng){
			cout << i - 1 << endl;
			return 0;
		}
		if(pos[i] > rng + 1) rng++;
	}
	cout << h << endl;
}
