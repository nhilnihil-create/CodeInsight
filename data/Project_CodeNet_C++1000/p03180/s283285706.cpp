#include <iostream>
#include <vector>
#define ll long long
#define int ll

using namespace std;

const int MOD = 1e9+7;
int a[20][20], dp[(1 << 16)], sum[(1 << 16)];

signed main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    //cout << "SUM :\n";
    for(int mask = 1; mask < (1 << n); mask++){
        ll x = mask;
        int d = 0;
        while(x){
            if(x & 1){
                //cout << "1 ";
            }
            else{
                //cout << "0 ";
            }
            d++;
            x >>= 1;
        }
        while(d < n){
            //cout << "0 ";
            d++;
        }
        //cout << ": ";
        ll ff = 0;
        for(int i = 0; i < n; i++){
            if((mask >> i) & 1){
                for(int j = 0; j < i; j++){
                    if((mask >> j) & 1){
                        ff += a[i][j];
                    }
                }
            }
        }
        sum[mask] = ff;
        //cout << sum[mask] << endl;
    }
    //cout << "DP :\n";

    for(int mask = 2; mask < (1 << n); mask += 2){
        ll x = mask;
        vector<int> bit;
        int z = 0;
        while(x){
            if(x & 1){
                bit.push_back(z);
            }
            z++;
            x >>= 1;
        }
        for(int j = 1; j < (1 << bit.size()); j += 2){
            ll w = j;
            int d = 0;
            ll aa = 0;
            while(w){
                if(w & 1){
                    aa += (1 << bit[d]);
                }
                d++;
                w >>= 1;
            }
            dp[mask] = max(dp[mask], dp[mask - aa] + sum[aa]);
        }
    }

    for(int j = 1; j < (1 << n); j += 2){
        dp[(1 << n)-1] = max(dp[(1 << n)-1], dp[(1 << n)-1 - j] + sum[j]);
    }
    cout << dp[(1 << n)-1];
}
