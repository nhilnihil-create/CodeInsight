#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    int n; cin >> n;
    map<int,int> mp;
    for(int i = 0; i < n; i++){int a; cin >> a; mp[a]++;}
    int m; cin >> m;
    for(int i = 0; i < m; i++) {
        int t; cin >> t;
        if(!mp[t]) {
            cout << "NO" << endl;
            return 0;
        }
        mp[t]--;
    }
    cout << "YES" << endl;
}