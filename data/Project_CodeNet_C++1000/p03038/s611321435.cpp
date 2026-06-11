#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define arr array

using namespace std;

const int e = 2e6 + 69;
const ll mod = 1e9 + 7;

ll a[e];
arr<int, 2>b[e];

//beginner 1999 127

int main()
{
    int n, m;
    cin >> n >> m;
    multiset<arr<int, 2>, greater<arr<int, 2>>>cur;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        cur.insert({a[i], 1});
    }
    for(int i=1; i<=m; i++){
        int x, y;
        cin >> x >> y;
        cur.insert({y, x});
    }
    int dem = n;
    ll ans = 0;
    /*for(auto j : cur){
        cout << j[0] <<" "<<j[1] <<"\n";
    }*/
    for(auto j : cur){
        ans += 1LL* min(dem, j[1])*j[0];
        dem -= min(dem , j[1]);
        if(dem == 0){
            cout << ans;
            return 0;
        }
    }

}
