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
    int n,d,x,ans=0;
    in n>>d>>x;
    vector<int> a(n);
    rep(i,n)in a[i];
    rep(i,n)
    {
        rep(j,d)
        {
            int hako=a[i]*j+1;
            if(hako<=d)ans++;
        }
    }
    cout<<ans+x<<endl;
}
