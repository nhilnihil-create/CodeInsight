#include <cstdio>
#include <vector>
#include <algorithm>

#define rep(i, n) for(int i = 0; i < n; ++i)

using namespace std;

int c[4];

int main(){
	rep(i, 6){
		int a;
		scanf("%d", &a);
		++c[a - 1];
	}
	int p = 0;
	rep(i, 4){
		p += c[i] == 2;
	}
	printf("%s", p == 2 ? "YES": "NO");
	return 0;
}