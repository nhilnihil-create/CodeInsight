#include <iostream>
using namespace std;
int main()
{
    int D;
	int N;
	int num = 1;
	int ans;
	
	cin >> D >> N;
    for (int i=0; i < D; ++i) {
		num *= 100;
	}
    if (num == 1) {
        if (N == 100) {
			ans = N + 1;
		} else {
			ans = N;
		}
    } else {
        if (N == 100) {
			ans = num * (N + 1);
		} else {
			ans = num * N;
		}
    }
    cout << ans << endl;
}
