#include <bits/stdc++.h>
using namespace std;

string smax(const string &l, const string &r){
    if (l == r)
        return r;
    if (l.size() != r.size())
        return l.size() > r.size() ? l : r;
    for (int i = 0; i < l.size(); i++){
        if (l[i] > r[i])
            return l;
        if (r[i] > l[i])
            return r;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> A(m);
    vector<int> Z = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    copy_n(istream_iterator<int>(cin), m, A.begin());
    vector<int> T(8, -1);
    for (const auto &a: A)
        T[Z[a]] = max(T[Z[a]], a);
    vector<pair<int, char>> B;
    for (int i = 0; i < 8; i++){
        if (T[i] > 0)
            B.push_back({i, T[i] + '0'});
    }

    vector<string> DP(n + 1, "");
    vector<bool> F(n + 1);
    F[0] = true;
    for (int i = 0; i < n; i++){
        if (!F[i]) continue;
        for (const auto &b: B){
            const int& j = b.first;
            if (i + j <= n){
                DP[i + j] = smax(DP[i + j], DP[i] + b.second);
                F[i + j] = true;
            }
        }
    }

    cout << DP[n] << endl;
}