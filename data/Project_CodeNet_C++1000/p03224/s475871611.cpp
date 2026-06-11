#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define xx first
#define yy second
using namespace std;
typedef long long ll;
const int N = 100010;
const ll mod = 998244353;
int a[N],b[N];
vector<int>v[N];
void solve(int p,int n)
{
    for(int i=1;i<=p;i++)
        v[i].clear();
    for(int i=1;i<=p;i++)
    {
        for(int j=i+1;j<=p;j++)
        {
            v[i].push_back(n);
            v[j].push_back(n--);
        }
    }
    printf("%d\n",p);
    for(int i=1;i<=p;i++)
    {
        printf("%d",v[i].size());
        for(int j=0;j<v[i].size();j++)
        {
            printf(" %d",v[i][j]);
        }
        printf("\n");
    }

}
int main()
{
    int n;
    scanf("%d",&n);
    if(n==1)
    {
        printf("Yes\n");
        printf("2\n1 1\n1 1\n");
        return 0;
    }
    for(int i=2;i<=n&&i*(i+1)<=n*2;i++)
    {
        if(i*(i+1)==n*2)
        {
            printf("Yes\n");
            solve(i+1,n);
            return 0;
        }
    }
    printf("No\n");
    return 0;
}
