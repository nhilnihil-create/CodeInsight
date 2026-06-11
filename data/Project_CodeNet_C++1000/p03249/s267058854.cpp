#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef vector<int> vi;
typedef map<ll, pii> mlp;

pli dfs1(vi e[], int x) {
    pli ret = pli(0, 1);
    for (int i : e[x]) {
        pli t = dfs1(e, i);
        ret.first += t.first + t.second;
        ret.second += t.second;
    }
    return ret;
}

void dfs2(vi e[], int x) {
    for (int i : e[x]) {
        cout << x + 1 << " " << i + 1 << endl;
        dfs2(e, i);
    }
}

int main() {
    int n;
    cin >> n;
    mlp dic;
    for (int i = 0; i < n; i++) {
        ll d;
        cin >> d;
        dic[d] = pii(i, 1);
    }

    vi e[n];
    bool f = true;
    for (auto it = dic.rbegin(); it != prev(dic.rend()); it++) {
        ll t = it->first - n + 2 * it->second.second;
        if (t >= it->first || !dic.count(t)) {
            f = false;
            break;
        }
        
        e[dic[t].first].push_back(it->second.first);
        dic[t].second += it->second.second;
    }
    
    f &= dfs1(e, dic.begin()->second.first).first == dic.begin()->first;

    if (!f) {
        cout << -1 << endl;
    } else {
        dfs2(e, dic.begin()->second.first);
    }

    return 0;
}