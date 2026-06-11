#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<long long>v;
    vector<pair<long long, int> >cards;
    for(int i = 0; i < n; i++){
        long long x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < m; i++){
        int x;
        long long y;
        cin >> x >> y;
        cards.push_back({y, x});
    }
    sort(cards.rbegin(), cards.rend());
    int p = 0;
    for(int i = 0; i < m; i++){
        int indx = upper_bound(v.begin() + p, v.end(), cards[i].first) - v.begin();
        if(indx <= p){
            break;
        }
        else{
            for(int q = p; q < min(indx, p + cards[i].second); q++){
                v[q] = cards[i].first;
            }
            p = min(indx, p + cards[i].second);
        }
    }
    long long ans = 0;
    for(int i = 0; i < n; i++){
        ans = ans + v[i];
    }
    cout << ans;
    return 0;
}