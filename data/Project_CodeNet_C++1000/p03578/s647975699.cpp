#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    map<int,int> mp;
    for(int i = 0; i < n; i++) {
        int d;
        cin >> d;
        mp[d]++;
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int t;
        cin >> t;
        if(mp[t]==0){
            cout << "NO" << "\n";
            return 0;
        }
        mp[t]--;
    }
    cout << "YES" << "\n";

    return 0;
}