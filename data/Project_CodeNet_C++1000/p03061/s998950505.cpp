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
using namespace std;

#define mod 1000000007
#define ten5 100005
#define ten52 200005
#define ten6 1000005
#define PI 3.1415926
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()

typedef long long int ll;

//stack<char> stk;
//set<ll> sll;
//map<string,ll> mp,mp1;
//map<string,ll>::iterator iter;
//map<ll,ll> mp;
//deque<char> deq;
//priority_queue<double> pq;
ll num[ten52],g[ten52],g2[ten52];


ll gcd(ll n,ll m)
{
    while(n>0 && m>0)
    {
        if(n>m)
            n%=m;
        else
            m%=n;
    }
    return n+m;
}

int main(void)
{
    long long int m,n,i,j,k=1;
    string s;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>num[i];
        g[i]=gcd(g[i-1],num[i]);
    }
    for(i=n;i>0;i--)
    {
        g2[i]=gcd(g2[i+1],num[i]);
        k=max(k,gcd(g2[i+1],g[i-1]));
    }
    cout<<k;
    return 0;
}
