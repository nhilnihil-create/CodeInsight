#include<bits/stdc++.h>
//#pragma comment(linker,"/STACK:1024000000,1024000000")
//251103FD
//4008802802
//4008160009
using namespace std;
#define PB pop_back
#define PF pop_front
#define np next_permutation
#define eb emplace_back
#define pb push_back
#define bf push_front
#define mp make_pair
#define s second
#define f first
#define foreach(it, a) for(__typeof((a).begin()) it=(a).begin(); it!=(a).end(); it++)
#define Foreach(it, a) for(__typeof((a).rbegin()) it=(a).rbegin(); it!=(a).rend(); it++)
#define forn(i, a) for(register int i=0; i<a; i++)
#define Forn(i, a) for(register int i=1; i<=a; i++)
#define memINF 127
#define all(x) x.begin(), x.end()
#define FAST ios::sync_with_stdio(false)
#define get(x) lower_bound(all(lisan), x)-lisan.begin()

typedef long long ll;
typedef pair<int,int> pi;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef unsigned int uint;

inline int in() 
{
    int x=0, c;
    while((uint)((c=getchar())-48)>=10) 
		if(c=='-') 
			return -in();
    do 
	{ x=(x<<3)+(x<<1)+(c^48); }
	while((uint)((c=getchar())^48)<10);
    return x;
}
inline int lcm(int a, int b){return a*b/__gcd(a, b);}

const int MAX=1e5+5;

int N, l, r, mid, BIT[MAX<<1], a[MAX], sum[MAX];
vi lisan;
ll k;

inline void Add(int *bit, int i, int x)
{
    while(i<=MAX*2-2)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}

inline int Sum(int *bit, int i)
{
    int ret=0;
    while(i)
    {
        ret+=bit[i];
        i-=i&-i;
    }
    return ret;
}

inline bool check(int x)
{
    memset(BIT, 0, sizeof(BIT));
    sum[0]=N+1;
    ll ret=0;
    forn(i, N)
        sum[i+1]=sum[i]+(a[i]<=x?1:-1);
    forn(i, N+1)
    {
        ret+=Sum(BIT, sum[i]-1);
        Add(BIT, sum[i], 1);
    }
    return ret*2>k;
}

int main()
{
    N=in();
    k=1LL*N*(N+1)/2;
    forn(i, N)
        a[i]=in(), lisan.pb(a[i]);
    
    sort(all(lisan));
    lisan.resize(unique(all(lisan))-lisan.begin());
    
    if(lisan.size()==1)
    {
        printf("%d\n", lisan.back());
        return 0;
    }
    
    l=0, r=lisan.size()+1;
    while(l+1<r)
    {
        mid=l+r>>1;
        if(check(lisan[mid]))
            r=mid;
        else
            l=mid;
    }
    printf("%d\n", lisan[r]);
    return 0;
}