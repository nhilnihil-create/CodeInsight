#include<math.h>
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ll long long int
#define py printf("Yes\n")
#define pn printf("No\n")
#define in cin>>
using namespace std;
const int INF = 1001001001;

int main()
{
    int a,b,k;
    in a>>b>>k;
    if(b-a>=2*k)
    {
        for(int i=a;i<a+k;i++)
        {
            cout<<i<<endl;
        }
        for(int i=b-k+1;i<b+1;i++)
        {
            cout<<i<<endl;
        }
    }
    else for(int i=a;i<b+1;i++)cout<<i<<endl;
}
