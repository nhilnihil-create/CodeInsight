#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

int main() {
	int a,b,h;
	cin>>a>>b;
	h=b-a;
	cout<<(h*(h+1)/2-b);
	return 0;
}
