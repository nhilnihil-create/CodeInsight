/**
 *    This code has been written by YueGuang, feel free to ask me question. Blog: http://www.yx.telstudy.xyz
 *    created:
 */
#include <cstdio>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#define REP(i, a, b) for(int i = a; i < b; i++)
#define REP_(i, a, b) for(int i = a; i <= b; i++)
#define sl(n) scanf("%lld", &n);
#define si(n) scanf("%d", &n);
#define RepAll(a) for(auto x: a)
#define cout(ans) cout << ans << endl;
typedef long long ll;

using namespace std;

int main()
{
    int  x, y;
    cin >> x >> y;
    ll  sum = 0;
    for(int i = y+1; i <= x;i++)
    {
        sum=sum+(i-y)*(x/i);
        if(x%i-y>=0)
            sum=sum+1+x%i-y;
    }
    if(y==0)
        sum=sum-x;
    cout<<sum <<endl;
    return 0;
}
