#include <bits/stdc++.h>
using namespace std;

long long dfs(string &S, long long n) {
    long long ret = 0;
    vector<char> list = {'3', '5', '7'};

    if ((int)S.size() > 0) {
        if (stoll(S) > n) {
            return ret;
        } else {
            bool flag = true;
            for (auto c : list) {
                if (S.find(c) == string::npos) {
                    flag = false;
                }
            }
            if (flag) {
                ret++;
            }
        }
    }
    
    for (auto c : list) {
        S.push_back(c);
        ret += dfs(S, n);
        S.pop_back();
    }
    return ret;
}


int main () {
    long long n;
    cin >> n;

    string S = "";
    long long ans = 0;

    ans = dfs(S, n);
    cout << ans << endl;

}

