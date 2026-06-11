#include<bits/stdc++.h>
// #define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
#define MOD 1000000007
using namespace std;
using ll = long long;
typedef vector<int> vi;


signed main() {
    string s;
    cin >> s;

    vi a(4);
    a[0] = s[0] - '0';
    a[1] = s[1] - '0';
    a[2] = s[2] - '0';
    a[3] = s[3] - '0';
    
    for(int bits = 0; bits < (1 << 3); bits++){
        int sum = 7 - a[0];
        for(int i = 0; i < 3; i++){
            if(bits&(1<<i)){
                sum += a[i+1];
            }else{
                sum -= a[i+1];
            }
        }
        if(sum == 0){
            cout << a[0] << ((bits&(1<<0)? '-' : '+'))<< a[1] << ((bits&(1<<1)? '-' : '+'))
            << a[2] << ((bits&(1<<2)? '-' : '+')) << a[3] << "=7\n";
            return 0;
        }
    }
}