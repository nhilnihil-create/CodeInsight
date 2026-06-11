#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define inf 1e18
#define pi acos(-1.0)
#define mod 1000000007

bitset<4000005>b;

int main(void)
{
    fastio;

    int n,a,s=0,i;
    cin >> n;
    b[0]=1;
    for(i=0;i<n;i++)
    {
        cin >> a;
        s=s+a;
        b=b|(b<<a);
    }
    for(i=(s+1)/2;i<=s;i++)
    {
        if(b[i])break;
    }
    cout << i ;

    return 0;
}

