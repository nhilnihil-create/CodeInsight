#include<bits/stdc++.h>
#define mxn 200005
using namespace std;
int pos[mxn], cnt[mxn];
int main()
{
    int n, x;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    scanf("%d", &x), pos[x]= i;
    int res= n;
    for(int i=n-1; i>=0; i--)
    {
        int rem= (n-i);
        cnt[i+1]= 1;
        if(pos[i+2]>pos[i+1])cnt[i+1]+= cnt[i+2];
        res= min(res, i+(rem-cnt[i+1]));
    }
    printf("%d\n", res);
    return 0;
}
