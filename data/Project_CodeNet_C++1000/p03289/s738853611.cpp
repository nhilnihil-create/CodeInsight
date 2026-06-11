#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <bitset>
#include<vector>
#include<utility>
#include<fstream>
#include<queue>
#include <iomanip>
#include<numeric>
#include<set>
#include<map>
#include<functional>
using namespace std;
#define rep(i, k) for (i = 0; i < k; i++) 
typedef long long ll;
typedef pair<ll, ll> l_l;
int i, j;

int main() {
	int a,b,k,z=0;
	string s;
	cin >> s;
	if (s[0] != 'A') {
		cout << "WA";
		return 0;
	}
	int c = 0;
	rep(i,s.length()){
		if (isupper(s[i]))c++;
	}
	if (c!=2) {
		cout <<"WA";
		return 0;
	}
	a = 0;
	for (i = 2; i < s.length() - 1; i++) {
		if (s[i] == 'C')a++;
	}
	if (a==0) {
		cout << "WA";
		return 0;
	}
	cout << "AC";
}

