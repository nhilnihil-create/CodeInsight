#include <bits/stdc++.h>

using namespace std;


int get_diameter_of_tree(vector<vector<int>>& adj_list) {
    function<pair<int, int> (int, int)> diam_and_longest = [&](int i, int parent) {
        int longest_1 = -1, longest_2 = -1;
        int diam = 0;
        for (int j : adj_list[i]) {
            if (j == parent) continue;
            auto p = diam_and_longest(j, i);
            diam = max(diam, p.first);
            int tmp_long = p.second;
            if (tmp_long >= longest_1) {
                longest_2 = longest_1;
                longest_1 = tmp_long;
            } else if (tmp_long >= longest_2) {
                longest_2 = tmp_long;
            }
        }
        diam = max(diam, longest_1 + longest_2 + 2);
        diam = max(diam, longest_1 + 1);
        return make_pair(diam, longest_1 + 1);
    };
    return diam_and_longest(0, -1).first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> adj_list(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int total_diam = get_diameter_of_tree(adj_list);
    cerr << "diam = " << total_diam << endl;
    
    if (total_diam % 3 == 1) {
        cout << "Second" << endl;
    } else {
        cout << "First" << endl;
    }
    
    return 0;
}
