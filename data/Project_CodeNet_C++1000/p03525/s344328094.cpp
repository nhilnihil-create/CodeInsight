#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    int n; cin >> n;
    vector<int> unit(13);
    unit[0]++;
    for(int i = 0; i < n; i++) {
        int a; cin >> a; unit[a]++;
        if(unit[a] == 3) {
            cout << 0 << endl;
            return 0;
        }
    }
    int ans = 0;

    for(int bit = 0; bit < (1 << 13); bit++) {
        vector<int> tim;
        for(int i = 0; i < 13; i++) {
            if((bit & (1 << i)) && unit[i] == 1) {
                tim.push_back(24 - i);
            } else {
                if(!unit[i])continue;
                tim.push_back(i);
                if(unit[i] == 1)continue;
                tim.push_back(24 - i);
            }
        }

        sort(tim.begin(), tim.end());
        tim.resize(unique(tim.begin(), tim.end()) - tim.begin()); 
        int m = tim.size();
        int nin = 13;

        for(int i = 0; i < m; i++) {
            for(int j = i + 1; j < m; j++) {

                int d = abs(tim[i] - tim[j]);
                if(d == 24)d = 0;
                nin = min(nin, min(d, 24 - d));

            }
        }
        ans = max(nin, ans);
    }
    cout << ans << endl;
}