#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define FORR(i,j,k,l) for(int i=j;i<=k;i+=l)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define clean(mat,n)   FOR(i,0,n) mat[i].clear()
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000007
#define M_PI           3.14159265358979323846  /* pi */
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

const int IT_MAX = 2e5;
int bit[IT_MAX + 10];


void update(int p, int v) ///change value of position p to v
{
	for (; p <= IT_MAX; p += p & (-p)) bit[p] += v;
}
int query(int p)
{
	int rv = 0;
	for (; p; p -= p & (-p)) rv += bit[p];
	return rv;
}


int n, ara[MAX], shut[MAX];

bool chk(int Val)
{
    LL ret = 0;

    mem(bit, 0);
    FOR(i,1,n)
    {
        shut[i] = shut[i - 1];
        if(ara[i] >= Val) shut[i]++;
        else shut[i]--;
    }

    FOR(i,0,n)
    {
       ret += query(shut[i] + n);
       if(i == n) break;
       update(shut[i] + n, 1);
    }

    if(ret * 2 >= (LL)n*(n+1)/2) return 1;
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    ///inf;
    //outf;

    cin >> n;
    FOR(i,1,n) cin >> ara[i];

    int st = 1, en = 1e9, mid, prin = 0;

    while(st <= en)
    {
        mid = (st + en)>>1;

        if(chk(mid)) prin  = max(prin, mid),
            st = mid + 1;
        else en = mid - 1;
    }

    cout << prin << endl;


    return 0;
}
