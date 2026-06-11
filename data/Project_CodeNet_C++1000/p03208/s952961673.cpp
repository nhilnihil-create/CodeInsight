#include <bits/stdc++.h>
#include <complex.h>
#include <math.h>
#include <iostream>
#include <ext/pb_ds/assoc_container.hpp> //required
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
using namespace std;
#define int ll
// fendwick tree
//#include <ext / pb_ds / assoc_container.hpp> //required
//#include <ext/pb_ds/tree_policy.hpp>         //required
using namespace __gnu_pbds; //required
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ordered_set<int> s;
ordered_set<int>::iterator itr;
// fendwick tree
/*
ll ans[200005];
void fun(ll a, ll b, ll c)
{
    //ll val = 1;

    while (a <= b)
    {
        ans[a] += c;
        ll p = -a;
        a += (a & p);
    }
}
ll find1(ll a)
{
    ll sum = 0;
    while (a != 0)
    {
        sum += ans[a];
        ll p = -a;
        a -= (a & p);
    }
    return sum;
}*/
int fastexpo(int a, int b, int m)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % m;
        b = b / 2;
        a = (a * a) % m;
    }
    return ans;
}
int32_t main()
{
    int t;
    int k;
    cin >> t >> k;
    int arr[t];
    int max1 = 0;
    int sum = 0;
    for (int i = 0; i < t; i++)
    {
        cin >> arr[i];
        // max1 = max(max1, arr[i]);
        sum += arr[i];
    }
    sort(arr, arr + t);
    int min1 = 100000000000;
    for (int i = t - 1; i >= 0; i--)
    {
        if (i - k >= -1)
            min1 = min(min1, arr[i] - arr[i - k + 1]);
    }
    cout << min1 << "\n";
    return 0;
}