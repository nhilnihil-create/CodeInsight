#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
vector<int> temp;
vector<vector<int>>vec;
int n;
void solve(int idx){
    if(idx >= n){
        vec.push_back(temp);
        return;
    }
    temp.push_back(idx);
    solve(idx + 1);
    temp.pop_back();
    solve(idx + 1);
}
int main(){
    Hello
    cin >> n;
    int c[n + 5], v[n + 5];
    for(int i = 0; i < n; i++)
        cin >> v[i];
    for(int i = 0; i < n; i++)
        cin >> c[i];
    solve(0);
    ll ans = 0;
    for(int i = 0; i < vec.size(); i++){
        ll x = 0, y = 0;
        for(int j = 0; j < vec[i].size(); j++){
            x += v[vec[i][j]];
            y += c[vec[i][j]];
        }
        ans = max(ans, x - y);
    }
    cout << ans;
    return 0;
}
