#include<bits/stdc++.h>
using namespace std;

#define deb(x) cerr<<"["#x<<" : "<<x<<" ]\n";
// 4x+7y=N;
int main()
{
	int N;
	cin >> N;
	for(int i = 0; i < N; i++) {
		if(N - i*4 < 0) break;
		if((N - i*4) % 7 == 0) {
			puts("Yes");
			return 0;
		}
	}
	puts("No");
}
