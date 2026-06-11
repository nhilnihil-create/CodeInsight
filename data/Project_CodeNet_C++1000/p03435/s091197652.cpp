#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <map>
#include <iomanip>
#include <math.h> 
#include <stack>
#include <queue>
#include <bitset>
#include <cstdlib>
#include <tuple>
#include <cctype>
#include <ctype.h>
#include <set>
#include <sstream>
#include <time.h>
#include <numeric>
using namespace std;
//#define int long long
#define rep(i,s,n) for(int i = s;i<n;i++)
#define repe(i,s,n) for(int i = s;i<=n;i++)
#define rrep(i,s,n) for(int i = (n)-1;i>=(s);i--)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define fi first
#define se second
#define chmin(a,b) a=min((a),(b))
#define chmax(a,b) a=max((a),(b))
#define l1 list[index]
#define l2 list[index - 1]
#define l3 list[index + 1]
#define iif(i,j) ((i<0 && j<0) || (i>0 && j>0)) ? true : false 
typedef long long ll;
//typedef pair<int, int>pint;
//typedef vector<int>vint;
//typedef vector<pint>vpint;
//typedef pair<pint, int> P1;
//typedef pair<int, pint> P2;
//typedef pair<pint, pint> PP;



int main(void) {
	vector<vector<int>>mat(3, vector<int>(3));

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> mat[i][j];

	bool flag2 = false;

	for (int i = 0; i <= mat[0][0]; i++) {
		int b[3] = { -1, -1, -1 };
		int a[3] = { i, -1, -1 };
		bool flag = false;

		for (int j = 0; j < 3; j++) {
			b[j] = mat[0][j] - i;
			if (b[j] < 0) {
				flag = true;
				break;
			}
		}

		if (flag == true)continue;

		if (mat[1][0] - b[0] >= 0 && mat[1][0] - b[0] == mat[1][1] - b[1] && mat[1][1] - b[1] == mat[1][2] - b[2]) {
			a[1] = mat[1][0] - b[0];
		}
		else continue;
		
		if (mat[2][0] - b[0] >= 0 && mat[2][0] - b[0] == mat[2][1] - b[1] && mat[2][1] - b[1] == mat[2][2] - b[2]) {
			a[2] = mat[2][0] - b[0];
		}
		else continue;

		flag2 = true;
		cout << "Yes" << endl;
		break;
	}

	if (flag2 == false)cout << "No" << endl;

	return 0;
}