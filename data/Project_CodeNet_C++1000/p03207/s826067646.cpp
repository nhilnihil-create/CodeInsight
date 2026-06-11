#include <bits/stdc++.h>
#include <complex.h>
#include <math.h>
#include <iostream>
#include <ext/pb_ds/assoc_container.hpp> //required
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
using namespace std;
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
long long int fastexpo(long long int a, long long int b, ll m)
{
    long long int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % m;
        b = b / 2;
        a = (a * a) % m;
    }
    return ans;
}
int main()
{
    int t;

    cin >> t;
    int arr[t];
    int max1 = 0;
    int sum = 0;
    for (int i = 0; i < t; i++)
    {
        cin >> arr[i];
        max1 = max(max1, arr[i]);
        sum += arr[i];
    }
    cout << sum - (max1 / 2) << "\n";
    return 0;
}