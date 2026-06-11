#include <bits/stdc++.h>

#define REPI(x) for(int i=0;i<x;i++)
#define REPJ(x) for(int j=0;j<x;j++)

using namespace std;

int main ()
{
    int N,cnt,res;

    scanf("%d",&N);
    
    res = 0;
    for (int i=1;i<=N;i++)
    {
        cnt = 0;
        for (int j=1;j<=i;j++)
        {
            if (i%j == 0)
                cnt++;
        }
        if (cnt == 8)        
            res++;
            
        i++;
    }

    printf("%d\n",res);
    return 0;
}