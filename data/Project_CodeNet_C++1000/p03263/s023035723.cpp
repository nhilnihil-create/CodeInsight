#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string.h>
#include <cstdio>
#include <tuple>
#include <numeric>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a,b) for(int i=a;i>b;i--)
#define vint vector<int> 
#define vvint vector<vint>
#define CST(x) cout<<fixed<<setprecision(x)//小数点以下の桁数指定
#define ct(a) cout<<a<<endl
static const double pi = 3.141592653589793;
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int INF = 1e9+7;
const int mod= 1e9 + 7;

int A[501][501];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int H, W; cin >> H >> W;

	FOR(i, 0, H) FOR(j,0,W){
		cin >> A[i][j];
	}

	vector<pair<pair<int,int>,pair<int, int>>> P;

	FOR(i, 0, H)FOR(j, 0, W) {
		if (A[i][j] % 2==1) {
			if (i == H - 1 && j<W-1) {
				pair<int,int> e1(i, j);
				pair<int, int> e2(i, j+1);
				P.emplace_back(e1,e2);
				A[i][j]--; A[i][j+1]++;
			}
			else if (j == W - 1 && i < H - 1) {
				pair<int, int> e1(i, j);
				pair<int, int> e2(i+1, j);
				P.emplace_back(e1, e2);
				A[i][j]--; A[i+1][j]++;
			}
			else if (i != H - 1 && j != W - 1) {
				if (A[i + 1][j] <= A[i][j + 1]) {
					
					pair<int, int> e1(i, j);
					pair<int, int> e2(i+1,j);
					P.emplace_back(e1, e2);
					A[i][j]--; A[i+1][j]++;
				}
				else {
					pair<int, int> e1(i, j);
					pair<int, int> e2(i, j+1);
					P.emplace_back(e1, e2);
					A[i][j]--; A[i][j+1]++;
				}
			}
		}
	}

	cout << int(P.size()) << endl;
	
	for (auto p : P) {
		auto a1 = p.first;
		auto a2 = p.second;
		cout << a1.first+1 << " " << a1.second+1 << " " << a2.first+1 << " " << a2.second+1 << endl;
	}
	

	return 0;
}
