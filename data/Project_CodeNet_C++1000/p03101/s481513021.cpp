#include <iostream>

using namespace std;

int main(void)
{
	int h, w, hh, ww;
	cin >> h >> w >> hh >> ww;

	cout << (h - hh)*(w - ww) << endl;
	
	return 0;
}