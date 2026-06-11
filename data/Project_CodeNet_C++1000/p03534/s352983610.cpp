#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
//#define mod 1000000007
#define PI acos(-1.0)
const long long MAX=200005;
typedef long long ll;
//const int INF=0x3f3f3f3f;
//int d[8][2]={-1,0,0,-1,0,1,1,0,1,1,-1,-1,-1,1,1,-1};
int n,m,t=0;
char b[9]={'A','K','I','H','A','B','A','R','A'};
char s[100005];
int a[5]={0};
int main()
{
    scanf("%s",&s);
    int l=strlen(s);
    for(int i=0;i<l;i++)
    {
        a[s[i]-'a']++;
    }
    int k=min(a[0],min(a[1],a[2]));
    for(int i=0;i<3;i++)
    {
        if(a[i]-k>=2)
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
