#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <stack>
#include <cmath>
using namespace std;

#define mod 1000000007
#define ten5 100005
#define ten52 200005
#define ten53 300005
#define ten6 1000005
#define PI 3.1415926
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define mkpr(x1,x2) make_pair(x1,x2)
typedef long long int ll;

vector<ll> vll[11];
ll num[ten52];

int main(void)
{
    ll m,n,i,j,k=1,d=0,sum=0,judge;
    string s,s1;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>k;
        for(j=0;j<k;j++)
        {
            cin>>d;
            d--;
            vll[i].pb(pow(2,d));
        }
    }
    for(i=0;i<m;i++)
        cin>>num[i];
    for(i=0;i<pow(2,n);i++)
    {
        for(j=0;j<m;j++)
        {
            d=judge=0;
            for(k=0;k<vll[j].size();k++)
                if((i&vll[j][k])==vll[j][k])
                    d++;
            //cout<<i<<'-'<<j<<'-'<<d<<endl;
            if((d&1)!=num[j])
            {
                judge=1;
                break;
            }
        }
        if(!judge)
            sum++;
    }
    cout<<sum;
    return 0;
}
