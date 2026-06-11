#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <list>
#include <numeric>
#include <map>	
#include <cmath>
#include <string>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define Cout(s) cout<<s<<endl
using namespace std;
typedef long long ll;
string Yes(bool b) { if (b) { return "Yes"; } else { return "No"; } }
string YES(bool b) { if (b) { return "YES"; } else { return "NO"; } }
//================================================
	

ll a = 1, b = 0, c, d, n, k = 0, ans = 0;
string s, t;

int main()
{
	int n, m; cin >> n;
	map<ll, int> flag;
	rep(i, n) { cin >> a; flag[a]++; }
  cin>>m;
	rep(i, m) {
		cin >> b;
		if (flag[b] == 0) { cout << "NO" << endl; return 0; }
		else flag[b]--;
	}
	cout << "YES" << endl;

	return 0;
}
