#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int H = 0;
	int W = 0;
	int h = 0;
	int w = 0;
	cin>>H>>W;
	cin>>h>>w;
	int res = (H-h)*(W-w);
	cout<<res;
	return 0;
}
