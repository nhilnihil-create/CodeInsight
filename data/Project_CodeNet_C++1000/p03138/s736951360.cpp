#include <cstdio>
#define maxn 100005
#define maxbits 45 // log2(1e12) < 40 < 45
using namespace std;

typedef long long LL;

LL a[maxn], k;
int cnt[maxbits][2], n;

template<typename T>
inline int countbit(T x)
{
	int cnt = 1;
	while(x >>= 1) cnt ++;
	return cnt;
}

int main(int argc, char** argv)
{
	// Input
	scanf("%d%lld", &n, &k);
	int maxc = -1;
	for(int i=0; i<n; i++)
	{
		scanf("%lld", a + i);
		int c = 0;
		while(true)
		{
			LL t = 1LL << c;
			if(a[i] < t) break;
			cnt[c++][int(bool(a[i] & t))] ++; // Add to bit count
		}
		if(c > maxc) maxc = c;
		do
		{
			cnt[c][0] ++;
		} while(++c < maxbits);
	}
	// Calculate x
	LL x = 0, ans = 0;
	for(int i=maxc-1; i>=0; i--)
	{
		x <<= 1LL;
		if(cnt[i][1] < cnt[i][0]) x ++;
	}
	if(x < k)
		if(maxc < countbit(k))
			x = k - k % (1LL << maxc) + x;
	if(x > k)
		if((x %= (1LL << countbit(k))) > k)
			for(int i=countbit(x)-1; i>=0; i--)
			{
				LL temp = 1LL << i;
				bool kbit = k & temp, xbit = x & temp;
				if(xbit == kbit) continue;
				if(kbit) break;
				x -= temp;
			}
	// Calculate & Print result
	for(int i=0; i<n; i++) ans += a[i] ^ x;
	printf("%lld\n", ans);
	return 0;
}