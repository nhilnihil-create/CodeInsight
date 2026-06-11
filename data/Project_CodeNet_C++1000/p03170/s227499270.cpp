#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define name "stones"
#define maxn 100005

using namespace std;

int n,k,a[105];
bool b[maxn];

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>k;
    f(i,1,n)
    {
        cin>>a[i];
    }
    f(i,0,k)
    {
        f(j,1,n)
        {
            if(i+a[j]<=k && b[i]==0)
            {
                b[i+a[j]]=1;
            }
        }
    }
    if(b[k]==1)
    {
        cout<<"First";
    }
    else
    {
        cout<<"Second";
    }

}
