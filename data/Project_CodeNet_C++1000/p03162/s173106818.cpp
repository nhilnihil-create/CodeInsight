//#define _GLIBCXX_DEB // Iterator safety; out-of-bounds access for Containers, etc.
//#pragma GCC optimize "trapv" // abort() on (signed) integer overflow.
#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define ll long long int
#define mod 1000000007
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define prec(n) fixed << setprecision(n)
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int>>
#define PI 3.1415926535897932384626
#define INF 1000000000
#define bits(n) __builtin_popcount(n)

int a[100001][3];
int f[100001][3];

void solve()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>a[i][j];
        }
    }
    f[0][0]=a[0][0];
    f[0][1] = a[0][1];
    f[0][2] = a[0][2];

    for(int day=1;day<n;day++)
    {
        f[day][0]=a[day][0]+max(f[day-1][1],f[day-1][2]);
        f[day][1] = a[day][1] + max(f[day - 1][0], f[day - 1][2]);
        f[day][2] = a[day][2] + max(f[day - 1][0], f[day - 1][1]);
    }
    int res1=f[n-1][0];
    int res2=f[n-1][1];
    int res3=f[n-1][2];
    cout<<max(max(res1,res2),res3);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input1.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output1.txt", "w", stdout);
#endif

    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
