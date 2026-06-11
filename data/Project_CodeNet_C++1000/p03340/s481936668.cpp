#include <iostream>
#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int a[200100][25];
int len[200100];
int b[25];

int main()
{
    int n;
    int i,j;
    ll res=0;

    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&j);
        while(j!=0){
            len[i]++;
            a[i][len[i]]=j%2;
            j=j/2;
        }
    }

    int l=1,r=1,fl=0;
    for(i=1;i<=21;i++)b[i]=a[1][i];
    while(l<=n){
        fl=0;
        r++;
        if(l==r&&l==n){
            res++;
            break;
        }
        if(r==n+1){
            ll k=r-l;
            res=res+k*(k+1)/2;
            break;
        }
        for(i=1;i<=len[r];i++){
            if(a[r][i]==1){
                if(b[i]==1){
                    ll k=r-l;
                    res=res+k;
                    for(i=1;i<=21;i++)b[i]=b[i]-a[l][i];
                    l++;
                    r--;
                    fl=1;
                    break;
                }
            }
        }
        if(fl==0){
            for(i=1;i<=21;i++)b[i]+=a[r][i];
        }
        //printf("%d %d %lld\n",l,r,res);
    }
    printf("%lld\n",res);




    return 0;
}
