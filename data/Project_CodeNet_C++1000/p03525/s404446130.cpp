#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> cnt(13);
    for(int i = 0; i < n; i++){
        int d;
        cin >> d;
        cnt[d]++;
    }
    vector<int> aa;
    aa.push_back(0);
    if(cnt[0] || cnt[12] >= 2){
        cout << 0 << endl;
        return 0;
    }
    if(cnt[12] == 1)
        aa.push_back(12);
    int ans = 0;
    for(int b = 0; b < (1 << 11); b++){
        vector<int> a = aa;
        for(int i = 0; i < 11; i++){
            int j = i+1;
            if(cnt[j] == 1){
                if(b >> j & 1)
                    a.push_back(j);
                else
                    a.push_back(24-j);
            } else if(cnt[j] == 2){
                a.push_back(j);
                a.push_back(24-j);
            } else if(cnt[j] >= 3){
                cout << 0 << endl;
                return 0;
            }
        }
        int mn = 24;
        a.push_back(24);
        sort(a.begin(), a.end());
        for(int i = 0; i+1 < a.size(); i++){
            if(mn > a[i+1]-a[i]) mn = a[i+1]-a[i];
        }
        if(ans < mn) ans = mn;
    }
    cout << ans << endl;
    return 0;
}