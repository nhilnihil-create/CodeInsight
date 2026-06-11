#include <bits/stdc++.h>
using namespace std;

//#define getchar getchar_unlocked
//#define putchar putchar_unlocked
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define ff first
#define ss second
#define err stderr
#define out stdout

typedef long long int ll;
typedef long double ld;
typedef short int sh;

inline void readI(int *i)
{
	register int t=0;
	register char z=getchar();
	int znak=1;
	if (z=='-')
	{
		znak=-1;
	}
	while ((z<'0') || ('9'<z))
	{
		z=getchar();
		if (z=='-')
		{
			znak=-1;
		}
	}
	while (('0'<=z) && (z<='9'))
	{
		t=(t<<3)+(t<<1)+z-'0';
		z=getchar();
	}
	*i=(t*znak);
}
inline void readUI(int *i)
{
	register int t=0;
	register char z=getchar();
	while ((z<'0') || ('9'<z))
	{
		z=getchar();
	}
	while (('0'<=z) && (z<='9'))
	{
		t=(t<<3)+(t<<1)+z-'0';
		z=getchar();
	}
	*i=t;
}
inline void readL(ll *l)
{
	register ll t=0;
	register char z=getchar();
	int znak=1;
	if (z=='-')
	{
		znak*=-1;
	}
	while ((z<'0') || ('9'<z))
	{
		z=getchar();
		if (z=='-')
		{
			znak=-1;
		}
	}
	while (('0'<=z) && (z<='9'))
	{
		t=(t<<3)+(t<<1)+z-'0';
		z=getchar();
	}
	*l=(t*znak);
}
inline void readUL(ll *l)
{
	register ll t=0;
	register char z=getchar();
	while ((z<'0') || ('9'<z))
	{
		z=getchar();
	}
	while (('0'<=z) && (z<='9'))
	{
		t=(t<<3)+(t<<1)+z-'0';
		z=getchar();
	}
	*l=t;
}
inline void writeL(ll l)
{
	if (l==0)
	{
		putchar(48);
	}
	else
	{
		if (l<0)
		{
		   l*=-1;
		   putchar(45);
		}
		int _tab[21];
		int wsk=0;
		while (l>0)
		{
			++wsk;
			_tab[wsk]=(l%10)+48;
			l/=10;
		}
		for (int j=wsk; j>=1; --j)
		{
			putchar(_tab[j]);
		}
	}
}
inline void writeS(string s)
{
	int l=s.length();
	for (int i=0; i<l; ++i)
	{
		putchar(s[i]);
	}
}
inline void space()
{
	putchar(32);
}
inline void endl()
{
	putchar(10);
}

#define debug if(0)
#define debug2 if(1)
#define debug3 if(1)
#define debug4 if(1)
#define MAXN 1005

int n, a, b, c;
struct trojka
{
	int w;
	int s;
	int v;
};
vector <trojka> v;
ll dp[MAXN*10];
ll odp;

bool comp(trojka a, trojka b)
{
	return a.s-b.w>b.s-a.w;
}
int main()
{
	readUI(&n);
	for (int i=1; i<=n; ++i)
	{
		readUI(&a);
		readUI(&b);
		readUI(&c);
		v.eb(trojka{a, b, c});
	}
	sort(v.begin(), v.end(), comp);
	for (int i=0; i<n; ++i)
	{
		int masa=v[i].w;
		int stam=v[i].s;
		int war=v[i].v;
		debug
		{
			fprintf (err, "i=%d masa=%d stam=%d war=%d\n", i, masa, stam, war);
		}
		for (int j=masa; j<=10000; ++j)
		{
			dp[min(stam, j-masa)]=max(dp[min(stam, j-masa)], dp[j]+war);
		}
		dp[stam]=max(dp[stam], (ll)war);
	}
	for (int i=0; i<=10000; ++i)
	{
		odp=max(odp, dp[i]);
	}
	fprintf (out, "%lld\n", odp);
	return 0;
}
/*
*/


