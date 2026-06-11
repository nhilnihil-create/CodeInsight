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
    int n, t;
    cin >> n >> t;
    vector<pair<int,int>> vec;
    for(int i = 1; i <= n; i++){
        int a, b; cin >> a>>b;
        if(b <= t){
            vec.pb({a,b});
        }
    }
    sort(vec.begin(), vec.end());
    if(vec.size() == 0)cout << "TLE" << endl;
    else cout << vec[0].f << endl;
    return 0;
}
