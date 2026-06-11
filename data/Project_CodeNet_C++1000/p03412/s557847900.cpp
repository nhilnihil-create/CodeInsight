//懒得打
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 200005;

long long a[N],b[N];
long long c[N],d[N];

bool f[35];

int main()
{
    int n;
    
    scanf("%d",&n);
    
    for (int i = 0;i < n;i++)
    {
        scanf("%lld",&a[i]);
    }
    
    for (int i = 0;i < n;i++)
    {
        scanf("%lld",&b[i]);
    }
    
    for (int i = 0;i <= 30;i++)
    {
        long long t = ((long long)1 << i);
        
        for (int j = 0;j < n;j++)
        {
            c[j] = a[j] % (2 * t);
            d[j] = b[j] % (2 * t);
        }
        
        sort(d,d+n);
        
        for (int j = 0;j < n;j++)
        {
            long long y = 2 * t - c[j];
            long long x = t - c[j];
            
            int p1 = lower_bound(d,d+n,x) - d;
            int p2 = lower_bound(d,d+n,y) - d;
            
            if (d[p2] >= y) p2--;
            if (p2 >= n) p2--;
            //if (p1 >= n) p1--;
            
            if (p2 >= p1 && (p2 - p1 + 1) % 2) f[i] = !f[i];
            
            y = 4 * t - c[j];
            x = 3 * t - c[j];
            
            p1 = lower_bound(d,d+n,x) - d;
            p2 = lower_bound(d,d+n,y) - d;
            
            if (d[p2] >= y) p2--;
            if (p2 >= n) p2--;
            //if (p1 >= n) p1--;
            
            if (p2 >= p1 && (p2 - p1 + 1) % 2) f[i] = !f[i];
        }
    }
    
    long long ans = 0;
    
    for (int i = 0;i <= 30;i++)
    {
        if (f[i]) ans |= ((long long)1 << i);
    }
    
    printf("%lld\n",ans);
    
    return 0;
}