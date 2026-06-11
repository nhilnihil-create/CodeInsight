#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    int n; cin >> n;
    vector<vector<int>> unit;

    if(n & 1) {
        for(int i = 0; i < n / 2; i++) {
            unit.push_back({i + 1, n - i - 1});
        }
        unit.push_back({n});
    } else {
        for(int i = 0; i < n / 2; i++) {
            unit.push_back({i + 1, n - i});
        }
    }


    int m = unit.size();
    vector<pair<int,int>> edge;

    for(int i = 0; i < m; i++) {
        for(int j = i + 1; j < m; j++) {

            for(auto k : unit[i]) {
                for(auto l : unit[j]) {
                    edge.push_back({k, l});
                }
            }
        }
    }

    cout << edge.size() << endl;
    for(auto i : edge)cout << i.first << " " << i.second << endl;
}