#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 105

int n , h;
bool used[MAXX];

int main()
{
    _FastIO;
    memset(used , true , sizeof(used));
    cin >> n;
    vector<pair<int , int> > v;
    for(int i = 0; i < n; i++){
        cin >> h;
        v.push_back({h , i});
    }
    sort(v.begin() , v.end());
    int ans = 0;
    while(!v.empty()){
        int x = v[0].first;
        int y = v[0].second;
        v.erase(v.begin());
        int s = 0;
        for(int i = 0; i < v.size(); i++){
            v[i].first -= x;
        }
        for(int i = 0; i < n; i++){
            if(used[i])
                s++;
            if(i && used[i] && used[i - 1])
                s--;
        }
        used[y] = false;
        ans += s * x;
    }
    cout << ans << endl;
    return 0;
}
