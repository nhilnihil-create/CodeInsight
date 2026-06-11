/*
    Author - Param Kothari
    Ah shit, here we go again
*/

#include <bits/stdc++.h>
 
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define mk make_pair

typedef long long ll;
typedef long double ld;

void solve(){
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> b(m);
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    vector<vector<int>> a(n, vector<int> (m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        int curr = 0;
        for(int j = 0; j < m; j++){
            curr += a[i][j] * b[j];
        }
        curr += c;
        res += (curr > 0);
    }
    cout << res << "\n";
    return;
}

int main(){
    IOS;
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    return 0;
}