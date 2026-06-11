#include <iostream>
#include <utility>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pii;

set<int> mp[200001];

int main() {
    int h,w,n,x,y;
    cin >> h >> w >> n;
    
    for(int i=0;i<n;++i) {
        cin >> x >> y;
        mp[y].insert(x);
    }

    for(int i=1;i<=w;++i) mp[i].insert(h+1);

    vector<Pii> v;
    int j_lower_lim = 1;
    for(int i=1;i<=w;++i) {
        while(mp[i].find(j_lower_lim) != mp[i].end()) ++j_lower_lim;
        set<int>::iterator j_itr = mp[i].upper_bound(j_lower_lim);
        if(j_itr != mp[i].end()) {
            v.emplace_back(*j_itr, i);
        }
        ++j_lower_lim;
    }
    sort(v.begin(), v.end());

    cout << v[0].first-1 << "\n";
}