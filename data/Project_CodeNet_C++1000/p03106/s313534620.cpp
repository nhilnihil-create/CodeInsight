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
	cin >>a>>b>> k;
	int c = 0;
	for (i = a; i >0 ;i--) {
		if (a % i == 0 && b % i == 0) {
			c++;
		//	cout << i << "\n";
		}
		if (c == k) {
			z = i;
			break;
		}
	}
	cout << z;
}
