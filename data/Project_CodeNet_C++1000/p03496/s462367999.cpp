#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define all(a) a.begin(), a.end()
#define F first
#define S second
#define pb push_back
#define ll long long
#define vi vector<long long>
#define sz(x) (int)x.size()
#define pi pair<long long, long long>
#define mp make_pair
#define endl '\n'
#define _ << ' '
#define min3(a, b, c) min(a, min(b, c))
#define min4(a, b, c, d) min(min(a, d), min(b, c))
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> idxset;
//find_by_order(i) : iterator to the value at index i, order_of_key(x) : the index of value x
const ll mod = (ll)1e9+7;
const ll INF = (ll)1e18+1;
const ll N = 2e5;

int n, a[50], mx=0, p=0, ind;
vector<int> neg, pos;
vector< pair<int, int> > ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    //freopen("B.txt", "r", stdin);
    #endif
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        if(a[i] < 0)
        {
            neg.pb(i+1);
            if(abs(a[i])>mx)
            {
                mx = abs(a[i]);
                p = 1; ind = i+1;
            }
        }
        else if(a[i] > 0)
        {
            pos.pb(i+1);
            if(a[i]>mx)
            {
                mx = a[i];
                p = 0; ind = i+1;
            }
        }
    }
    if(p)
    {
        for(auto i : pos)
        {
            ans.pb({ind, i});
        }
        for(int i=n-2; i>=0; i--)
        {
            ans.pb({i+2, i+1});
        }
    }
    else
    {
        for(auto i : neg)
        {
            ans.pb({ind, i});
        }
        for(int i=0; i<n-1; i++)
        {
            ans.pb({i+1, i+2});
        }
    }
    cout << sz(ans) << endl;
    for(auto p : ans) cout << p.F _ << p.S << endl;
}
