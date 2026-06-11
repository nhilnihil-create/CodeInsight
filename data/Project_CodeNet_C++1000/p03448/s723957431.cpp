#include <iostream>

using namespace std;

int main() {
	int a, b, c, x; //aが500円、bが100円、cが50円
	int count = 0;
	cin >> a >> b >> c >> x;
	
	for (int i = 0; i <= a; i++) {
		for(int j = 0; j <= b; j++ ){
			for(int k = 0; k <= c; k++ ){
				if (x == 500 * i + 100 * j + 50 * k) count = count + 1;
			}
		}
	}

	cout << count;

	return 0;
}