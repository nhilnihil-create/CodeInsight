#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <limits>
#include <unordered_map>

using namespace std;
using str = string;

#define rep(a,l,r) for(int a=(l);a<(r);a++)
#define get cin>>
#define put cout<<

void run() {

	long a; get a;
	long b; get b;

	if (a + b == 15) {
		put "+";return;
	}

	if (a * b == 15) {
		put "*"; return;
	}

	put "x"; return;

}

int main() {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);run();return 0;}
