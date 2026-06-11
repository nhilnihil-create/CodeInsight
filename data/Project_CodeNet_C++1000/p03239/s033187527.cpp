#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

int n , T;
int c , t;

int main()
{
    _FastIO;

    cin >> n >> T;
    vector<pair<int , int> > v;
    while(n--){
        cin >> c >> t;
        v.push_back({t , c});
    }
    sort(v.begin() ,v.end());
    if(v[0].first > T){
        cout << "TLE" << endl;
        return 0;
    }
    int ans = 1000;
    for(int i = 0; i < v.size(); i++){
        if(v[i].first > T)
            break;
        ans = min(ans , (v[i].second));
    }
    cout << ans << endl;
    return 0;
}
