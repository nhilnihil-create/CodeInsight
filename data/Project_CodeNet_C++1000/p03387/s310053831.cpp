#include<bits/stdc++.h>
// #define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
#define MOD 1000000007
using namespace std;
using ll = long long;
typedef vector<int> vi;


signed main() {
    vi a(3);
    cin >> a[0] >> a[1] >> a[2];

    int cnt = 0;
    while(!(a[0] == a[1] && a[0] == a[2])){
        // cout << a[0] << " " << a[1] << " " << a[2] << endl;
        sort(a.begin(), a.end());
        if(a[2] - a[0] > 1){
            a[0] += 2;
            cnt++;
        }else if(a[2] - a[0] == 1){
            a[2] -= 1;
            cnt++;
        }
    }
    
    cout << cnt << endl;
}