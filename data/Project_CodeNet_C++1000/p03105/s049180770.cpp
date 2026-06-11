#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iomanip>
#define ull unsigned long long
#define ll long long
#define pb push_back
#define tle ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int mod = 998244353;
const int mxn = 2e5 +7;
int _,n,m,t,k,u,v,ans,cnt,ok,lim;
ll w[mxn] , cost[mxn] ,  far[mxn] , siz[mxn];
char ch;
#define lc now<<1
#define rc now<<1|1
string str ;
struct node {ll l,r,val,lazy,mx,mn;}p[mxn<<4];
int lmx1[mxn] , rmx1[mxn] , lmx0[mxn] , rmx0[mxn] , num1[mxn] , num0[mxn] , lazy[mxn];
int calc()
{

}
int main()
{tle;
    int Case = 1 ;
    int a,b,c;
    cin>>a>>b>>c;
    cout<<min(b/a,c)<<endl;
}