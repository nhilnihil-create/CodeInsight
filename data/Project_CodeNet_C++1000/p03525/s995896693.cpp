#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
int INF = 1000000009;
int main()
{
    int n;
    cin >> n;
    if(n>=24){
        cout << 0 << endl;
        return 0;
    }
    int d[n];
    int mp[24]={};
    mp[0] = 1;
    vector<int> v[2];
    int cnt = 0;
    rep(i, n)
    {
        cin >> d[i];
        if(mp[d[i]]==0){
            if(d[i]!=12)cnt++;
            mp[d[i]]++;
        }else{
            if(mp[24-d[i]]==0){
                cnt--;
                mp[24 - d[i]]++;
                mp[d[i]]++;
            }else{
                cout << 0 << endl;
                return 0;
            }
        }
    }
    rep(i,11){
        if(mp[i+1]!=1)continue;
        v[0].push_back(i + 1);
        v[1].push_back(24 - (i + 1));
    }
    int k = 1 << cnt;
    int ans = 0;
    rep(i,k){
        int x = i;
        vector<int> v2;
        v2.push_back(0);
        v2.push_back(24);
        if(mp[12])v2.push_back(12);
        rep(j,11){
            if(mp[j+1]==2){
                v2.push_back(j+1);
                v2.push_back(24 - (j + 1));
            }
        }
        rep(j,cnt){
            v2.push_back(v[x % 2][j]);
            x /= 2;
        }
        int tmp = 50;
        rep(j, v2.size())
        {
            rep(k,v2.size()){
                if(j==k)continue;
                tmp = min(abs(v2[k] - v2[j]), tmp);
            }
        }
        ans = max(tmp, ans);
    }
    cout << ans << endl;
}