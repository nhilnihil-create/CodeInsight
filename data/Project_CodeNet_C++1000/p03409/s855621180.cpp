#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
int main()
{
    int n, a, b;
    cin >> n;
    vector<pair<int, int>> p_red;
    rep(i, n){
        cin >> a >> b;
        p_red.emplace_back(a, b);
    }
    vector<pair<int, int>> p_blue;
    rep(i, n){
        cin >> a >> b;
        p_blue.emplace_back(a, b);
    }
    sort(p_red.begin(), p_red.end());
    sort(p_blue.begin(), p_blue.end());

    int ans = 0;
    rep(i, n){
        int idx = 0;
        int m = 0;
        bool ok = false;
        rep(j, p_red.size()){
            if(p_blue[i].first > p_red[j].first && p_blue[i].second > p_red[j].second){
                ok = true;
                if(m <= p_red[j].second){
                    idx = j;
                    m = p_red[j].second;
                }
            }
            else if(p_blue[i].first <= p_red[j].first){
                break;
            }
        }
        if(ok){
            p_red.erase(p_red.begin() + idx);
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}