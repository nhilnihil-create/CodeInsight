/********************************************
 *Author*        :ZZZZone
 *Created Time*  : 日  3/11 21:07:02 2018
 * Ended  Time*  : 五  3/23 15:31:02 2018
*********************************************/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <stack>
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
typedef unsigned long long ULL;
const int MAXN = 3e5;

inline void OPEN(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

LL n, a, b;

void solve()
{
    if(a+b>n+1||a*b<n)///第一个条件很容易知道 第二个条件就写写找找看吧。。
    {
        cout<<-1;
        return ;
    }
    while(n>0)///每轮都是构造一个递增的子序列
    {
        LL x=min(a,n-b+1);///每一轮都取递增数和递减数中较小的那个
        //cout<<"x="<<x<<endl;
        for(LL i=n-x+1;i<=n;i++)
            cout<<i<<" ";
        n-=x;///x 为这一轮构造的递增子序列的个数
        b--;///递减的值 b 每一轮 -1
    }
}
int main()
{
    while(cin>>n>>a>>b)
    {
        solve();
        cout<<endl;
    }
    return 0;
}


