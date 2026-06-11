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
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> all(n);
    for(int i = 0; i < n; i++){
        cin >> all[i].first >> all[i].second;
    }
    sort(all.begin(), all.end(), [&](const pair<int, int> &x, const pair<int, int> &y){
        if(x.first == y.first)
            return x.second > y.second;
        return x.first < y.first;
    });
    ll res = 0, curr = m;
    for(auto p : all){
        ll no = p.second;
        // cout << no << " " << curr << " " << res << "\n";
        if(no <= curr){
            res += (no * p.first);
            curr -= no;
        }
        else{
            res += (curr * p.first);
            curr = 0;
        }
        if(curr <= 0)
            break;
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