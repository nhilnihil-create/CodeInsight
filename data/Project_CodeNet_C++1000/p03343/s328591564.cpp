#include <cstdio>
#include <set>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
#include<numeric>
#include <list>
#define fo(a, b, c) for (register int a = b; a <= c; ++a)
 
namespace IO
{
//    inline char gc()
//    {
//        static char s[1<<20|1]={0},*p1=s,*p2=s;
//        return (p1==p2)&&(p2=(p1=s)+fread(s,1,1<<20,stdin),p1==p2)?EOF:*(p1++);
//    }
	inline char gc() { return getchar(); }
	inline long long read()
	{
		long long ret=0;bool flag=0;char c=gc();
		while ((c<'0')|(c>'9')) flag ^= !(c^'-'),c=gc();
		while ((c>='0')&(c<='9')) ret=(ret<<1)+(ret<<3)+(c^'0'),c=gc();
		return flag?-ret:ret;
 	}
 	char OutputAns[1<<20|1],*OutputCur = OutputAns;
 	inline void output()
 	{
 		OutputCur -= fwrite(OutputAns,1,OutputCur - OutputAns,stdout);
	}
	inline void print(long long ans)
	{
		char s[20]={0};
		if (OutputCur - OutputAns + sprintf(s,"I64d",ans) >> 20) output();
		OutputCur += sprintf(OutputCur,"%I64d",ans);
	}
	inline void printc(char c)
	{
		if (OutputCur - OutputAns + 1 >> 20) output();
		*(OutputCur++) = c;
	}
}
 
using IO::read;
using IO::print;
using IO::printc;
using IO::output;
 
using namespace std;
 
typedef long long int64;
 
const int M = 2e3 + 11;
 
int lim, n, q, ans = 2e9;

int A[M], R[M], Ok[M], C[M];

inline void Input()
{
	n = read(), lim = read(), q = read();
	for (int i = 1;i <= n; ++i)
		A[i] = R[i] = read();
	std::sort(R + 1, R + 1 + n);
}

inline void Solve(int Min)
{
	Ok[0] = 0;
	int l = 1, r = 1;
	while (l <= n)
	{
		C[0] = 0;
		while (A[l] < Min && l <= n) ++l;
		r = l;
		while (A[r] >= Min && r <= n) ++r;
		if (r - l < lim) goto end;
		for (int i = l;i < r; ++i)
			C[++C[0]] = A[i];
		std::sort(C + 1, C + 1 + C[0]);
		for (int i = 1;i <= C[0] - lim + 1; ++i)
			Ok[++Ok[0]] = C[i];
		end:; l = r;
	}
	if (Ok[0] < q) return ;
	std::sort(Ok + 1, Ok + 1 + Ok[0]);
	ans = std::min(ans, Ok[q] - Ok[1]);
}

int main(void)
{
	Input();
	for (int i = 1;i <= n - lim + 1; ++i)
		Solve(R[i]);
	printf("%d\n", ans);
	return 0;
}