/*****************************************
Author: lizi
Email: lzy960601@outlook.com
*****************************************/
  
#include<bits/stdc++.h>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))
#define fi first
#define se second
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;

int n,k;
int a[1005][1005];

int main()
{
    scanf("%d",&n); k=0;
    for(int i=2;true;i++)
    {
        if(i*(i-1)/2 > n)break;
        if(i*(i-1)/2 == n) {k=i;break;}
    }
    if(k==0){puts("No");return 0;}
    puts("Yes");
    printf("%d\n",k); int cnt=0;
    for(int bs=1;bs<k;bs++)
    {
        for(int i=bs;i<k;i++)a[bs][i]=cnt+i-bs+1;
        for(int i=bs;i<k;i++)a[i+1][bs]=cnt+i-bs+1;
        cnt+=k-bs;
    }
    for(int i=1;i<=k;i++)
    {
        printf("%d",k-1);
        for(int j=1;j<k;j++)printf(" %d",a[i][j]);
        puts("");
    }
    return 0;
}
