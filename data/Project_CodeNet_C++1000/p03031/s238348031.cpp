#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    long long n, m;
    cin >> n >> m;

    vector<vector<long long> > s(m);
    for(long long i = 0; i < m; i++){
        long long k;
        cin >> k;
        for(long long j = 0; j < k; j++){
            long long a;
            cin >> a;
            s[i].push_back(a);
        }
    }

    long long p[m];
    for(long long i = 0; i < m; i++) cin >> p[i];


    vector<bool> switch_on(n);
    long long ans = 0;
    for(long long bit = 0; bit < (1 << n); bit++){
        for(long long mask = 0; mask < n; mask++){
            if(bit & (1 << mask)) switch_on[mask] = true;
            else switch_on[mask] = false;
        }

        long long light = 0;
        for(long long i = 0; i < m; i++){
            long long cnt_on = 0;
            for(long long j = 0; j < s[i].size(); j++){
                if(switch_on[s[i][j]-1] == true) cnt_on++;
            }
            if(p[i] == cnt_on % 2)light++;
        }
        if(light == m) ans++;
    }
    cout << ans << endl;
    return 0;
}