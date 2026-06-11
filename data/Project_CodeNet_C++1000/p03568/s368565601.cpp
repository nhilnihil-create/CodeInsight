#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>	
#include <cmath>
#include <string>
#include<math.h>//���炵���̂Œ���
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define Cout(s) cout<<s<<endl
using namespace std;
typedef long long ll;
string Yes(bool b) { if (b) { return "Yes"; } else { return "No"; } }
string YES(bool b) { if (b) { return "YES"; } else { return "NO"; } }
//================================================

int a = 1, b = 0, c, d, n, k = 0, ans = 0;
string s, t;
int mod = 1000000007;

int main()
{
	cin >> n;
	vector<int> a(n); rep(i, n)cin >> a[i];
	int ans = 1;
	rep(i, n) {
		if (a[i] % 2 == 0)
			ans *= 2;
	}
	cout << pow(3, n) - ans << endl;

	return 0;
}
