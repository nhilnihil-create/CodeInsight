#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<string.h>
#include<queue>
#include <set>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int main()
{
    int n;
    int a[105][105];
    int dp[105][105];
    while(scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=2; i++)
            for(int j=1; j<=n; j++)
                scanf("%d",&a[i][j]);
        dp[1][1]=a[1][1];
        for(int i=1; i<=2; i++)
            for(int j=1; j<=n; j++)
            {
                if(i==1)
                    dp[i][j]=dp[i][j-1]+a[i][j];
                else
                    dp[i][j]=max(dp[i-1][j]+a[i][j],dp[i][j-1]+a[i][j]);

            }

        printf("%d\n",dp[2][n]);
    }
    return 0;
}
/*
5
3 2 2 4 1
1 2 2 2 1
*/
//using namespace std;
//char s[1000005];
//int a[1000005];
//vector<int>v[1000005];
//int main()
//{
//    //vector<int>v[1000004];
//    set<int>q;
//    memset(a,0,sizeof(a));
//    scanf("%s",s);
//    int len=strlen(s);
//    if(s[0]=='1')
//        a[1]=1;
//    else
//        a[1]=-1;
//    v[0].push_back(0);
//    for(int i=1; i<len; i++)
//    {
//        if(s[i]=='1')
//            a[i+1]=a[i]+1;
//        else
//            a[i+1]=a[i]-1;
//        q.insert(a[i+1]);
//        v[a[i+1]].push_back(i+1);
//    }
//    int sum=0;
//    set<int>::iterator iter = q.begin();
//    for(iter; iter!=q.end(); iter++)
//    {
//        int qq=*iter;
//        int ze=v[qq].size();
//        if(ze==1)
//            continue;
//        sum=max(sum,v[qq][ze-1]-v[qq][0]);
//    }
//
//
//    printf("%d\n",sum);
//    return 0;
//
//}
//int main()
//{
//   int a[1005];
//   int t;
//   scanf("%d",&t);
//   while(t--)
//   {
//       int n;
//       scanf("%d",&n);
//       for(int i=1;i<=n;i++)
//        scanf("%d",&a[i]);
//        int i=1;
//        int sum=0,nn=n,kai=1;
//        if(a[1]==n)
//        {
//            while(a[i]==nn)
//            {
//                i++;
//                nn--;
//                sum++;
//            }
//            if(a[i]==1)
//            {
//                while(a[i]==kai)
//                {
//                    kai++;
//                    i++;
//                    sum++;
//                }
//            }
//        }
//        if(sum==n)
//            printf("No\n");
//        else
//            printf("Yes\n");
//    }
//    return 0;
//}
//
