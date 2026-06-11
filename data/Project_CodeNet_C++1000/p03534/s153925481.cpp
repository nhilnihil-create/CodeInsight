#include<bits/stdc++.h>
#define PLI pair<ll,int>
#define PII pair<int, int>
#define X first
#define Y second
#define MP make_pair
#define PLL pair<ll, ll>
#define ll long long
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define N 100010
const double eps = 1e-6;
using namespace std;

int Read()
{
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    return x * f;
}
ll ReadL()
{
    ll x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    return x * f;
}
char s[N];
int cnt[4];

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    while(scanf("%s", s) != EOF)
    {
        int l = strlen(s);
        cnt[0] = cnt[1] = cnt[2] = 0;
        for(int i = 0; i < l; i ++)
            cnt[s[i]-'a'] ++;
        sort(cnt, cnt + 3);
        if(cnt[2] - cnt[0] > 1) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
