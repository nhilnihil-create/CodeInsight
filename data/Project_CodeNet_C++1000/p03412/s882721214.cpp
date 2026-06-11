#include <bits/stdc++.h>
using namespace std;

const int N = 200006;

int a[N];
int b[N];

int aa[N],bb[N];

int n;

int cal(int L,int R)
{
    if (L>R) return 0;
    return upper_bound(bb+1,bb+n+1,R) - lower_bound(bb+1,bb+n+1,L);
}

int main ()
{
    //int n;
    scanf("%d",&n);
    for (int i=1;n>=i;i++)
    {
        scanf("%d",&a[i]);
    }
    for (int i=1;n>=i;i++)
    {
        scanf("%d",&b[i]);
    }
    int ans=0;
    for (int k=0;30>k;k++)
    {
        for (int i=1;n>=i;i++)
        {
            aa[i] = (a[i]&((1<<(k+1))-1));
            bb[i] = (b[i]&((1<<(k+1))-1));
        }
        sort(bb+1,bb+n+1);
        long long num=0;
        for (int i=1;n>=i;i++)
        {
            int L1 = (1<<k),R1 = (1<<(k+1))-1;
            int L2 = L1 + (1<<(k+1)),R2 = R1 + (1<<(k+1));
            num += cal(L1-aa[i],R1-aa[i]) + cal(L2-aa[i],R2-aa[i]);
            //cout << "i = " << i << " , num = " << num << endl;
        }
        //cout<< "k = " <<k<< " , num = " << num<<endl;
        ans |= (num&1)*(1<<(k));
    }
    printf("%d\n",ans);
}
