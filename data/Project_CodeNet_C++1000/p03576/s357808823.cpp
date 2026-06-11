#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LONG_LONG_MAX / 2;

int main() {
    ll N, K; cin >> N >> K;
    vector<pair<ll,ll>> v(N);
    for (ll i = 0; i < N; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    
    ll min_area = INF;
    for (ll i = 0; i < N; i++)
    {
        for (ll j = 0; j < N; j++)
        {
            if(v[i].first>v[j].first) continue;
            for (ll k = 0; k < N; k++)
            {
                for (ll l = 0; l < N; l++)
                {
                    if(v[k].second>v[l].second) continue;
                    ll area = (v[j].first-v[i].first) * (v[l].second-v[k].second); 
                    if(area > min_area) continue;
                    ll cnt = 0;
                    for (ll m = 0; m < N; m++)
                    {
                        if(v[i].first<=v[m].first && v[j].first>=v[m].first && v[k].second<=v[m].second && v[l].second>=v[m].second){
                          cnt++;  
                        }                        
                    }
                    if(cnt>=K) min_area = min(min_area, area);
                }
            }
        }
    }
    cout << min_area << endl;
}