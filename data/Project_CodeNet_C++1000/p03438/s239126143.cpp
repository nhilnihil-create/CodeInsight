#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <set>
#include <queue>
#include <map>
#include <stack>
using namespace std;

#define mod 1000000007
#define ten5 100005
#define ten52 200005
#define ten6 1000005
#define PI 3.1415926
#define pb(x) push_back(x)
#define mkpr(x,y) make_pair(x,y)
#define all(x) x.begin(),x.end()

typedef long long int ll;

ll general,total;
ll num[ten5];
ll num2[ten5];
//char cmap[10][10];
//priority_queue<ll> pqll;   //decrease
//priority_queue<double> pqd;
//stack<int> stk;
//vector<pair<ll,ll>> vpll;
//vector<pair<double,double>> vpdd;
//vector<ll> vll[ten52];
//vector<double> vd;
//deque<ll> deq[55];
//list<int> li;
//set<int> sint;
//set<ll> sll;
//map<ll,ll> mp;

/*ll cmp(pair<ll,ll> a,pair<ll,ll> b)
{
    return a.first<b.first;
    //arrising
}*/


int main()
{
    double ans=0.0,half,d,d1,d2;
    //float f,g,h;
    string s,s1;
    //char now,pre,c1,c2;
    long long int sum,sum2,n1,n2,n3;
    long long int m,n,o,i,j,k=1;
    long long int a,a1,a2,a3,a4,a5,a6;
    sum=sum2=n1=n2=n3=0;
    a=a1=a2=a3=a4=a5=a6=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>m;
        num[i]=m;
    }
    for(i=0;i<n;i++)
    {
        cin>>m;
        num2[i]=m;
    }
    for(i=0;i<n;i++)
    {
        a=num[i]-num2[i];
        if(a>0) sum2+=a;
        else
        {
            a=abs(a);
            if(a&1==1)
            {
                sum+=(a+1)/2;
                sum2++;
            }
            else sum+=a/2;
        }
    }
    if(sum2>sum) cout<<"No";
    else cout<<"Yes";
    return 0;
}



