#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define F first
#define S second
#define int long long

const int maxn = 5e5+10;
const ll inf = 1e18+10;
const int mod = 998244353;

int n, m, k;
vector<pair<int,int>> edge;

void add(int u, int v)
{
    edge.push_back({u,v});
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string s;
    cin>> s; n = s.size();
    s = "*" + s;

    vector<int> a;
    for(int i = 1; i < n; i++)
    {
        if(s[i] != s[n-i])
            return cout<< -1 <<"\n", 0;
        if(s[i] == '1')
            a.push_back(i);
    }
    if(s[n] == '1' || s[1] == '0')
        return cout<< -1 <<"\n", 0;

    int nd = 1;
    for(int i = 1; i < a[0]; i++)
        nd++, add(nd,1);

    int lst = 1;
    for(int i = 1; i < a.size(); i++)
    {
        nd++;
        int X = nd;
        for(int j = 1; j < a[i]-a[i-1]; j++)
            nd++, add(nd,X);
        add(X,lst);
        lst = X;
    }
    nd++;
    add(nd,lst);

    for(auto e : edge)
        cout<< e.F <<" "<< e.S <<"\n";
}

