#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0 ; i < (int)(n) ; i++)
typedef long long ll;
typedef long double Double;

#ifndef INPUTS_DIR
#define INPUTS_DIR "./"
#endif


ll solve(vector<ll> x, ll C, vector<ll> v) {
    vector<ll> maximumCost;
    maximumCost.push_back(0);
    {
        ll sm = 0;
        for (int i = x.size() - 1; i >= 0; i--) {
            sm += v[i];
            maximumCost.push_back(sm - (C - x[i]) * 2);
        }
    }
    for (int i = 1; i < maximumCost.size(); i++) {
        maximumCost[i] = max(maximumCost[i], maximumCost[i - 1]);
    }


    ll sum = 0;
    ll ans = maximumCost[x.size()];
    for (int i = 0; i < x.size(); i++) {
        sum += v[i];
        ans = max(ans, sum - x[i] + maximumCost[x.size() - i - 1]);
    }
    return ans;
}


void solve(ll N, ll C, vector<ll> x, vector<ll> v) {
    ll ans1 = solve(x, C, v);
    reverse(x.begin(), x.end());
    reverse(v.begin(), v.end());
    for (auto &&i : x)
        i = C - i;
    ll ans2 = solve(x, C, v);
    cout << max(ans1, ans2) << endl;
}


void main_(istream &cin) {
    ll N;
    ll C;
    cin >> N;
    vector<ll> v(N - 1 + 1);
    vector<ll> x(N - 1 + 1);
    cin >> C;
    for (int i = 0; i <= N - 1; i++) {
        cin >> x[i];
        cin >> v[i];
    }
    solve(N, C, x, v);
}

int main() {
#ifdef INTELLIJ
    ifstream ifs(string(INPUTS_DIR) + "in_1.txt");
    if (ifs.is_open()) {
        main_(ifs);
        ifs.close();
    } else {
        cerr << "Error: no input." << endl;
    }
#else
    ios::sync_with_stdio(false);
    cin.tie(0);
    main_(cin);
#endif
}



