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
    int a,b,c,x,ans=0;
    in a>>b>>c>>x;
    for(int i=0;i<=a;i++)
    {
        for(int j=0;j<=b;j++)
        {
            for (int k=0;k<=c;k++)
            {
                if(500*i+100*j+50*k==x)ans++;
            }

        }
    }
    cout<<ans<<endl;
}
