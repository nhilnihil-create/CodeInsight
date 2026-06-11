#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define f first
#define s second
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m, x, y;
    vector<int> vec, vec2;
    cin >> n >> m >> x >> y;
    int z;
    for(int i = 0; i < n; i++){
        int t; cin >> t; vec.pb(t);
    }
    for(int i = 0; i < m; i++){
        int t; cin >> t; vec2.pb(t);
    }
    sort(vec.begin(),vec.end()); sort(vec2.begin(), vec2.end());
    for(int i = max(x, vec[vec.size()-1])+1; i <= min(y, vec2[0]); i++){
        cout << "No War" << endl; return 0;
    }
    cout << "War" << endl;
    return 0;
}
