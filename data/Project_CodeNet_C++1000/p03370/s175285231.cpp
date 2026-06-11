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
    int n,x,tmp=0;
    in n>>x;
    vector<int> m(n);
    int ans=n;
    rep(i,n){
        in m[i];
        tmp+=m[i];
    }
    int hako = x-tmp;
    sort(m.begin(), m.end());
    while(hako>=0)
    {
        hako-=m[0];
        ans++;
    }

    cout<<ans-1<<endl;
}
