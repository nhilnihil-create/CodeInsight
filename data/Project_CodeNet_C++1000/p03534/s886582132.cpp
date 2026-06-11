#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second

char s[100010];

int main()
{
	int c[3]={0,0,0};
	scanf("%s", s);
	for(int i=0; s[i]; ++i) c[s[i]-'a']++;
	sort(c, c+3);
	if(c[2]-c[0] <= 1) puts("YES");
	else puts("NO");
	return 0;
}
