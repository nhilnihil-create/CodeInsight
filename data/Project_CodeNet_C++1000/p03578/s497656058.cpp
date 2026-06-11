#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

using namespace std;

// long long gcd(long long a, long long b){
//     if (a < b){
//         a ^= b;
//         b ^= a;
//         a ^= b;
//     }
//     return b ? gcd(b, a % b) : a;
// }

// long long lcm(long long a, long long b){
//     return a * b / gcd(a, b);
// }

int main(){
    long long n,d[200001],m,t[200001];
    map<long long, long long> mpd,mpt;
    cin >> n;
    rep(i,n){
        cin >> d[i];
        mpd[d[i]]++;
    }
    cin >> m;
    rep(i,m){
        cin >> t[i];
        mpt[t[i]]++;
    }
    
    rep(i,m){
        if(mpt[t[i]] > mpd[t[i]]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    
    return 0;
}
