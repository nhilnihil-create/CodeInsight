#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int n; vector<int> odd,even;
void input()
{
    cin >> n;
    for(int i=0; i<n/2; ++i){
        int a,b; cin >> a >> b;
        odd.emplace_back(a);
        even.emplace_back(b);
    }
}

bool pair_compare(pair<int,int> a, pair<int,int> b)
{
    return a.first > b.first;
}

void solve()
{
    map<int,int> Modd,Meven;
    Modd[0]; Meven[0];
    for(auto x: odd) Modd[x]++;
    for(auto x: even) Meven[x]++;

    vector<pair<int,int>> oddMap, evenMap;
    for(auto m: Modd){
        oddMap.emplace_back(make_pair(m.second,m.first));
    }
    sort(oddMap.begin(),oddMap.end(),pair_compare);
    for(auto m: Meven){
        evenMap.emplace_back(make_pair(m.second,m.first));
    }
    sort(evenMap.begin(),evenMap.end(),pair_compare);

    if(oddMap[0].second == evenMap[0].second){
        cout << min(n - oddMap[0].first - evenMap[1].first, n - oddMap[1].first - evenMap[0].first) << endl;
    }
    else cout << n - oddMap[0].first - evenMap[0].first << endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}