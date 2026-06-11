#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;

int f[105][15], p[105][15];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 10; j++){
            cin >> f[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 11; j++){
            cin >> p[i][j];
        }
    }
    ll mx = -2e9;
    for(int i = 1; i < (1 << 10); i++){
        int cnt[100]{};
        for(int j = 0; j < 10; j++){
            if(i >> j & 1){
                for(int k = 0; k < n; k++){
                    if(f[k][j]) cnt[k]++;
                }
            }
        }
        ll sum = 0;
        for(int j = 0; j < n; j++){
            sum += p[j][cnt[j]];
        }
        mx = max(sum, mx);
    }
    cout << mx;

    return 0;
}
