#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstring>
#define ll long long
#define INF 1000000000
#define For(i,a,b) for(int i=a;i<=b;++i)
#define Rev(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
#define pq priority_queue
#define PI acos(-1)

namespace IO
{
#define p(x) ('0'<=x&&x<='9')
	char cc; int C;
	template <class T>
	void read( T &x )
	{
		x=0; cc=getchar(); C=1;
		while(!p(cc)) { if(cc=='-') C=-1; cc=getchar(); }
		while(p(cc)) { x=x*10+cc-48; cc=getchar(); }
		x*=C;
	}
#undef p
}

using namespace IO;
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	srand(time(0));
#ifdef LOCAL
	freopen("./tmp/input.txt", "r", stdin);
#endif

	char s[10];

	scanf("%s",s);
	For(i,0,2) s[i]='0'+'0'+10-s[i];
	printf("%s\n",s);

	return 0;
}
