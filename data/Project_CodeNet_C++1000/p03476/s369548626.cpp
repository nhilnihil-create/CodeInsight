
#include<bits/stdc++.h>
#define lln long long int
#define llu unsigned lln
#define sc(n) scanf("%d",&n);
#define scl(n) scanf("%lld",&n);
#define scd(n) scanf("%lf",&n);
#define pf(res) printf("%d\n",res);
#define pfl(res) printf("%lld\n",res);
#define pfd(res) printf("%lf\n",res);
#define maxii 100005
using namespace std;
typedef pair<int,int> pii;
typedef pair<lln,lln> pll;
typedef vector<int> vi;
typedef vector<lln> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;


int arr[maxii];
int arr2[maxii];
int p=0;
bool prim[maxii];

void prime()
{
    for(int i=3;i*i<=maxii;i+=2)
    {
        if(prim[i]==false)
        {
            for(int j=i*i;j<=maxii;j+=i+i)
            {
                prim[j]=true;
            }
        }
    }
    arr[3]=1;
    for(int i=3;i<=maxii;i+=2)
    {
        int x=(i+1)/2;
        //cout<<i<<" "<<x<<endl;
        if(prim[i]==false && prim[x]==false && x%2!=0 )
        {
            arr[i]=1;
        }
    }

}

int main()
{
    prime();
    for(int i=1;i<=maxii;i++)
    {
        arr[i]=arr[i]+arr[i-1];
        //cout<<arr[i]<<" "<<i<<endl;
    }
    int q;
    sc(q)
    for(int i=1;i<=q;i++)
    {
        int x,y;
        sc(x)
        sc(y)
        pf(arr[y]-arr[x-1]);
    }

}





