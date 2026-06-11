#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <vector>

using namespace std;
#define LL long long
#define ri register int

template<typename T>inline void read(T& x) {
	x = 0;
	int f = 0;
	char ch = getchar();
	for (;!isdigit(ch);ch = getchar())
		f |= (ch == '-');
	for (;isdigit(ch);ch = getchar())
		x = (x << 1) + (x << 3) + (ch ^ 48);
	x = f ? -x : x;
}

int n;
int s[1010][1010];
int main(){
	read(n);
	int x = 1,tot;
	for(x = 1,tot = 0;;++x){
		tot += x;
		if(tot == n) {
			break;
		}
		if(tot > n)
			return puts("No"),0;
	}
	puts("Yes");
	printf("%d",x + 1);
	int last = 0;
	for(int i = 1;i <= x + 1;++i){
		printf("\n%d ",x);
		for(int j = 1;j < i;++j)
			printf("%d ",s[j][i - 1]);
		for(ri j = i;j <= x;++j)
			printf("%d ",s[i][j] = ++last);
	}
	return 0;
}
