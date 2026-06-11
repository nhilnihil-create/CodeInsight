#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define pb push_back
#define mk make_pair
#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
#define f2(i,a,b) for(int i=(a);i<=(b);i++)
#define sf(a) scanf("%d",&a);
#define sfl(a) scanf("%lld",&a);
#define pf(a) printf("%d\n",a);
#define pfl(a) printf("%lld\n",a);
#define TEST int test; cin >> test;while(test--)
#define ii pair<int,int>
#define iil pair<ll,ll>
#define loop(i,a,b) for(int i = a ; i < b ; i++)
#define INF 2147483647


int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[] = {0, 0, 1, -1};
int dy4[] = {1, -1, 0, 0};
const double pi = acos(-1.0);

map<ll,ll>mp;
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int f = 0;
    vector<int> v, v1;
    //if(s[0] == '0') v.pb(0);
    if(s[0] == '0') v.pb(1);
    if(s[0] == '0' && s[1] == '1') v1.pb(1);

    for(int i = 1 ; i < n ; i++)
    {

        if(s[i] == '0' && s[i-1] == '1') v.pb(i+1);

        if(s[i] == '0' && s[i+1] == '1') v1.pb(i+1);

    }
//    for(int i = 0 ; i < v.size() ; i++){
//    cout << v[i] << " ";
//    }
//    cout << endl;
    int ans = -1;
    if(v.size() <= k)
    {
        cout << n << endl;
        return;
    }
    else
    {
        v.pb(n+1);
        ans = v[k] - 1;

        //v.insert(v.begin(),0);
        for(int i = k+1 ; i < v.size() ; i++)
        {
                ans = max(ans, v[i] - v1[i - k - 1]  - 1);

        }
    }

    // cout << ans <<endl;
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //TEST
    solve();
    //main();
    return 0;
}
