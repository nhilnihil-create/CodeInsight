#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <map>
const int MOD = 1e9+7;
#define PI 3.14159265359
typedef long long ll;
using namespace std;

int col[501][501];
int d[501][501];
int mod0[31];
int mod1[31];
int mod2[31];

int main(){
	int n, c;
	cin >> n >> c;

	for (int i = 1; i <= c; i++){
		for (int j = 1; j <= c; j++){
			cin >> d[i][j];
		}
	}
	int cnt0 = 0, cnt1 = 0, cnt2 = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> col[i][j];
			if ((i+j) % 3 == 0) mod0[col[i][j]]++;
			if ((i+j) % 3 == 1) mod1[col[i][j]]++;
			if ((i+j) % 3 == 2) mod2[col[i][j]]++;
		}
	}
	int ans = MOD;
	for (int i = 1; i <= c; i++){
		for (int j = 1; j <= c; j++){
			for (int k = 1; k <= c; k++){
				if (i != j && j != k && k != i){
					int temp = 0;
					for (int l = 1; l <= c; l++){
						temp += d[l][i]*mod0[l];
						temp += d[l][j]*mod1[l];
						temp += d[l][k]*mod2[l];
					}
					ans = min(ans, temp);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}