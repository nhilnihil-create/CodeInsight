#include <iostream>
#include <cstdio>
#include <sstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
ll ans,maxn;
int main()
{
    long long x;
    ll div;
    cin>>x;
    maxn=sqrt(x);
    for(ll i=1;i<=maxn;i++)
    {
        if((x-i)%i==0){div=(x-i)/i;
        if(div>i)ans+=div;
        }
    }
    cout<<ans<<endl;
    return 0;
}
