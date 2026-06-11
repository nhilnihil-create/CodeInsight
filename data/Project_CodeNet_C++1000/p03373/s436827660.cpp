

#include <iostream>
#include <vector>
#include <bitset>
#include <utility>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(){
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;

	int t;
	if(y<x) {
		t=y;y=x;x=t;
		t=b;b=a;a=t;
	}

	int r;
	r=min({2*y*c, 2*x*c+(y-x)*b, a*x+b*y});

	cout << r << endl;

	return 0;

}


