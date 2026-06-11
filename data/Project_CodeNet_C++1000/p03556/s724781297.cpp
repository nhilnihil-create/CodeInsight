#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;

	for(int loop = N; loop >= 1; --loop) {
		int tmp = sqrt(loop);
		if(tmp * tmp == loop) {
			cout << loop <<endl;
			return 0;
        }
    }

	return 0;
}
