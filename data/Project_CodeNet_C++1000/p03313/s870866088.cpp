#pragma GCC optimize "03"
#include "bits/stdc++.h"
using namespace std;
 
#define ll long long int
#define ld long double
#define pi pair<int, int>
#define pb push_back
#define fi first
#define se second
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#ifndef LOCAL
#define endl '\n'
#endif
 
const int N = 6e5 + 5;
const int B = 19;
const int mod = 1e9 + 7;
const int inf = 1e9 + 9;
 
int p[B], a[N];
vector<int> v[N];

bool cmp(int x, int y){
    return a[x] < a[y];
}

signed main() {
    IOS;
    #ifdef LOCAL
        freopen("input.txt","r", stdin);
        freopen("output.txt","w",stdout);
    #endif
    p[0] = 1;
    for(int i = 1; i < B; i++)
        p[i] = (p[i-1] << 1);
    int n, ans = 0;  cin >> n;
    for(int i = 0; i < p[n]; i++){
        int x;  cin >> x;
        a[i] = x;
        v[i].push_back(i);
        sort(v[i].begin(), v[i].end(), cmp);
        v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
        reverse(v[i].begin(), v[i].end());
        /*cout << i << endl;
        for(auto j: v[i])
            cout << a[j] << " ";
        cout << endl;*/
        while(v[i].size() > 2)
            v[i].pop_back();
        for(int b = 0; b < B; b++){
            if(!(p[b]&i)){
                v[p[b]+i].push_back(v[i][0]);
                v[p[b]+i].push_back(v[i][1]);
            }
        }
        if(i >= 1){
            ans = max(ans, a[v[i][0]] + a[v[i][1]]);
            cout << ans << endl;
        }
    }
    return 0;
}