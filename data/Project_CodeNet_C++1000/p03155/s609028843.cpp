#include <iostream>
using namespace std;

int n, w, h;

int main()
{
	cin >> n >> h >> w;
	h--, w--;
	cout << (n - h) * (n - w) << endl;
}