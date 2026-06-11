#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef double db;
typedef vector <ll> vll;
typedef pair <ll, ll> pll;
#define pb push_back
#define mp make_pair
#define MAX 1000000
#define mod 1000000007
#define all(_) _.begin(), _.end()
#define F first
#define S second
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
ll solve(string s, ll k)
{
    ll d = 0, c = 0, m = 0, mc = 0;
    for(ll i = 0; i < k; i++)
    {
        if(s[i] == 'D')
            d++;
        else if(s[i] == 'M')
            m += d, mc++;
        else if(s[i] == 'C')
            c += m;
    }
    for(ll i = k; i < s.size(); i++)
    {
        if(s[i - k] == 'D')
        {
            m -= mc;
            d--;
        }
        else if(s[i - k] == 'M')
            mc--;
        if(s[i] == 'D')
            d++;
        else if(s[i] == 'M')
            m += d, mc++;
        else if(s[i] == 'C')
            c += m;
    }
    return c;
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    string s;
    ll n, q, i;
    cin >> n >> s >> q;
    vll k(q);
    for(i = 0; i < q; i++)  
        cin >> k[i];
    for(auto x : k)
        cout << solve(s, x) << endl;
    return 0;
}