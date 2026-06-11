#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

int a[maxn];
int n;

int id[maxn], num[maxn], top;
bool check(int MAX)
{
    //printf("%d\n",MAX);
    top=0;
    id[top]=1;
    num[top]=a[0];
    top++;
    for(int i=1;i<n;i++)
    {
        if(a[i]>a[i-1]){
            num[top]=a[i]-a[i-1];
            id[top]=1;
            top++;
        }
        else{
            int last = a[i-1];
            while(last > a[i]){
                if(last - num[top-1] >= a[i]){
                    last-=num[top-1];
                    top--;
                }
                else{
                    num[top-1]-=(last-a[i]);
                    last=a[i];
                }
            }
            bool flag=0;
            for(int j=top-1; j>=0; j--)
            {
                if(id[j]<MAX){
                    if(num[j]==1){
                        id[j]++;
                        top=j+1;
                    }
                    else{
                        num[j]--;
                        num[j+1]=1;
                        id[j+1]=id[j]+1;
                        top=j+2;
                    }
                    flag=1;
                    break;
                }
                last-=num[j];
            }
            if(flag){
                if(last!=a[i]){
                    num[top]=a[i]-last;
                    id[top]=1;
                    top++;
                }
            }
            else {
                //printf("%d is fail\n",i);
                return false;
            }
        }
    }
    return true;
}
int main() {
    scanf("%d",&n);
    for(int i=0; i < n; i++)
    {
        //a[i]=2;
        scanf("%d", a + i);
    }
    //printf("%d",check(3));
    //return 0;
    int l = 1, r = n, ans=1;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid)){
            r=mid-1;
            ans=mid;
        }
        else{
            l=mid+1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
