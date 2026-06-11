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
#define sz(x) ((int)(x).size())
#define Cout(s) cout<<s<<endl
typedef long long ll;
using namespace std;
string Yes(bool b) { if (b) { return "Yes"; } else { return "No"; } }
string YES(bool b) { if (b) { return "YES"; } else { return "NO"; } }
//================================================

int a = 0, b = 0, c, d, n, k = 0;
string s, t;



int main()
{
	int n;
	cin >> n >> a;
	cout << n - a + 1 << endl;

	return 0;
}